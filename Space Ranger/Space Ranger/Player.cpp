#include "Player.h"

std::string shipfile = "Textures/spritesheet.png";

void Player::initVariables()
{
	this->movementSpeed = 4.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile(shipfile))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->rectSourceSprite = sf::IntRect(1496, 0, 1496, 1736);
	this->sprite.setTextureRect(rectSourceSprite);
	//Resize the sprite
	this->sprite.scale(0.1f, 0.1f);
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

const sf::Vector2f & Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int & Player::getHp() const
{
	return this->hp;
}

const int & Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

int last_move = 0;
void Player::move(const float dirX, const float dirY)
{
	if (dirX == -1.f && dirY == 0.f && last_move != 1) { last_move = 1; this->rectSourceSprite.left = 0; this->rectSourceSprite.width = 1496; this->sprite.setTextureRect(rectSourceSprite); }
	else if (dirX == 1.f && dirY == 0.f && last_move != 2) { last_move = 2;  this->rectSourceSprite.left = 2992; this->rectSourceSprite.width = 1496;  this->sprite.setTextureRect(rectSourceSprite); }
	else if (dirX == 0.f && dirY == -1.f && last_move != 3) { last_move = 3; this->rectSourceSprite.left = 1496; this->rectSourceSprite.width = 1496;  this->sprite.setTextureRect(rectSourceSprite);}
	else if (dirX == 0.f && dirY == 1.f && last_move != 3) { last_move = 3;  this->rectSourceSprite.left = 1496; this->rectSourceSprite.width = 1496;  this->sprite.setTextureRect(rectSourceSprite);}
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::powerup(const int poiiintss)
{
	if (poiiintss >= 80) {
		this->rectSourceSprite.top = 1736;
		this->sprite.setTextureRect(rectSourceSprite);
	}
}

void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
