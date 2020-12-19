#include "Game.h"
#include "Menu.h"

int main() {
	int gamestart = 0;
	sf::RenderWindow windoWW(sf::VideoMode(1920, 1080), "Space Ranger StartMenu", sf::Style::Fullscreen);

	Menu menu(windoWW.getSize().x, windoWW.getSize().y);
	menu.startmusic();
	menu.initBG();
	while (windoWW.isOpen()) {
		sf::Event event;
		while (windoWW.pollEvent(event)) {
			
			switch (event.type) {
				case sf::Event::KeyReleased:
					switch (event.key.code) {
						case sf::Keyboard::Up:
						menu.MoveUp();
						break;
						case sf::Keyboard::Down:
						menu.MoveDown();
						break;
						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
							case 0:
								std::cout << "Play\n";
								gamestart = 1;
								//std::cout << gamestart << "\n";
								menu.stopmusic();
								windoWW.close();
								break;
							case 1:
								std::cout << "Options\n";
								break;
							case 2:
								std::cout << "Exit\n";
								windoWW.close();
								break;
							default:
								break;
							}
					}
					break;

				case sf::Event::Closed:
				windoWW.close();
				break;
			}
		}
		windoWW.clear();
		menu.draw(windoWW);
		windoWW.display();
		if (gamestart == 1) {
			windoWW.clear();
			windoWW.close();
			Game game; //creating a game instance
			game.run();//running a funtion of game, this is where my game comes into existance
			//ENd
		}
	}
	
	return 0;
}