#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("fonts/astro.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("High Scores");
	menu[2].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(menubg);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << "Up pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << "Down pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::startmusic()
{
	if (!music.openFromFile("music/bg.ogg")) {
		std::cout << "cant open music";
	}

	music.play();
}

void Menu::stopmusic()
{
	music.stop();
}

void Menu::initBG()
{
	if (!menubgTex.loadFromFile("textures/menu1080.jpg")) {
		std::cout << "Cant load BG\n";
	}
	menubg.setTexture(menubgTex);
}

void Menu::drawBG()
{
}
