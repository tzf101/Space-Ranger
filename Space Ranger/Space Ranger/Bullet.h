#ifndef BULLET_H //i dunno why i used this
#define BULLET_H //NOKI
#endif
#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet
{
private:
	sf::Sprite shape;//the sprite for the bullet, the texture comes from the map variable we used in game.h
	sf::Vector2f direction;//its a SFML special variable which will act as a direction variable(like struct{ int x, y; })
	float moveSpeed;//speed of the bullet
public:

	Bullet();//check bullet.cpp
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();
	//Accessor to get bullet's boundary position, mainly for detecting collision and removing them when out of the screen
	const sf::FloatRect getBounds() const;//returns the bounds of the sprites
	void update();//updating the bullet with the latest data
	void render(sf::RenderTarget* target);//rendering the bullet but as a reference as we are modifying a already drawn bullet
};

