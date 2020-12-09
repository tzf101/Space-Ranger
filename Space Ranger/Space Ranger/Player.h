#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Player
{
private:
	sf::Sprite sprite; // means the object of the image file used for the player
	sf::Texture texture;// texture is the image file, texture is what sits as a skin on the sprite
	float movementSpeed;//the speed at which the spaceship moves
	float attackCooldown;//determines how many shots the ship can fire before cooldown
	float attackCooldownMax;//maximum shots before cooldown
	//private functions
	void initVariables();//init means initialize
	void initTexture();
	void initSprite();
public:
	Player();//check player.cpp to understand
	virtual ~Player();
	//Accessor to get the area of the player, mainly to detect collision
	const sf::Vector2f& getPos() const;

	const bool canAttack();//checking whether the weapon is having a cooldown

	void move(const float dirX, const float dirY);//moving the ship
	
	void updateAttack();//updating the cooldown state, if it is not reached

	void update();//updating the player with the latest pointer

	void render(sf::RenderTarget& target);//we used the player as a pointer so that we can controll it by reference, thats why we passed its reference in the render funtion which will draw it
};

