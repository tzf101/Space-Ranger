#include "Game.h"


//this whole shit is self explanitory

void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Ranger", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("textures/bullet.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}


Game::Game()
{
	this->initwindow();
	this->initTextures();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;//removing them to stop memory leak
	delete this->player;//removing them to stop memory leak
	for (auto &i : this->textures)//removing them from the window to stop memory leak
	{
		delete i.second;
	}
	for (auto *i : this->bullets)//removing them from the vector to stop memory leak
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.sf::Event::type == sf::Event::Closed) //clse by clicking close button
		{
			this->window->close();
		}
		if (e.sf::Event::KeyPressed && e.sf::Event::key.code == sf::Keyboard::Escape)//closing using escape key 
		{
			this->window->close();
		}
	}
}
void Game::updateBullets()
{
	unsigned counter = 0;//the ith bullet
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) // outside of the top screen
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter); //deleting the bullet which is out of the top screen
			--counter;//as element removed, the vector container elements are 1 short
		}
		++counter;//iterating to the next element in the bullet vector
	}
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f));
	}
}


void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateBullets();
}

void Game::render()
{
	//clearing everything that was drawn before
	this->window->clear();
	//drawing elements
	this->player->render(*this->window);
	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	//displaying it
	this->window->display();
}
