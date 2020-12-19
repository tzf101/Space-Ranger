#pragma once
#include "Player.h"
#include "Bullet.h"

#include<map>
class Game
{
private:
	//variables
	sf::RenderWindow* window;//the game window
	//resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;//this stores and keeps track of the bullets
	//player
	Player* player; //using it as a pointer because we need to pass it and work on the same object, as a reference
	void initwindow();//creating the window
	void initTextures();//adding texture to the bullets, using the map variable here
	void initPlayer();//creating the player in the game for the first time
public:
	//public funtion
	Game();//check game.cpp to understand
	virtual ~Game();
	void run();
	void updatePollEvents();//dhore ne eta diye keyboard input check kortesi, jusst like wut u did in khbit
	void updateInput();//input onushare processing game
	void updateBullets();//processing bullets
	void update();//updating the whole game window with the updated values
	void render();//rendering the scene
};

