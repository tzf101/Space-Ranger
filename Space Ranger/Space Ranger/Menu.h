#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
#include <iostream>
#include <SFML/Audio.hpp>
class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() {return selectedItemIndex;}
	void startmusic();
	void stopmusic();
	void initBG();
	void drawBG();
private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite menubg;
	sf::Texture menubgTex;
	sf::Music music;
};

