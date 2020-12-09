#include "Player.h"
#include <iostream>

//this shit is also self explanitory

void Player::initVariables()
{
	this->movementSpeed = 1.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initTexture()
{
	//load texture from file
	if (!this->texture.loadFromFile("textures/ship.png")) {
		std::cout << "cannot load ship.png\n";
	}
}

void Player::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture); 
	this->sprite.scale(0.2f, 0.2f);
}


Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
