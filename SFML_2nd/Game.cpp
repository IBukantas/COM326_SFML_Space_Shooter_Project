#include "Game.h"

// Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Run, Gun, Robot", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("images/projectile_image.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemy()
{
	this->enemy = new Enemy();
}

// Constructors / Deconstructors
Game::Game()
{
	this->initWindow();
	this->initTextures();

	this->initPlayer();
	this->initEnemy();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	// Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}
}

// Functions
void Game::run()
{
	// While window is open, update new frames 
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updateMousePositions()
{
	/*
	* Updates mouse positions:
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updatePollEvents()
{
	// Check for events 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			// TODO: When escape is pressed open menu
			;
		}
	}
}

void Game::updateInput()
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0, 1.f);
	}

	// Update mouse position
	this->updateMousePositions();

	//
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 15.f));
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets)
	{
		bullet->update();

		// Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;

		std::cout << this->bullets.size() << "\n";	// Shows number of bullet instances


	}
}

void Game::update()
{
	// TODO: Update player velocity


	this->updatePollEvents();
	this->updateInput();

	this->player->update();

	this->updateBullets();

}

void Game::render()
{
	// Clear last frame
	this->window->clear();

	// Draw all the objects
	this->player->render(*this->window);
	this->enemy->render(*this->window);
	
	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	// Show new frame
	this->window->display();
}
