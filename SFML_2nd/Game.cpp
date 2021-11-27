#include "Game.h"

// Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Run, Gun, Robot", sf::Style::None);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("images/projectile_image.png");
}

void Game::initGUI()
{
	// Load font
	if (!this->font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	}

	// Initialise point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(24);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Test: 123");
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;
}

// Constructors / Deconstructors
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	// Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	// Delete enemies
	for (auto* i : this->enemies)
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
	// Updates mouse positions

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updatePollEvents()
{
	// Check for events 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
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

	// When left mouse button is pressed create new bullet
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 15.f));
	}
}

void Game::updateGUI()
{

}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
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

		//std::cout << "Number of bullets: " << this->bullets.size() << "\n";	// Shows number of bullet instances
	}
}

void Game::updateEnemies()
{
	// Spawning
	this->spawnTimer += 0.5f;

	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20, -300.f));

		this->spawnTimer = 0.f;
	}

	// Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		// Enemy culling (top of screen)
		if (enemy->getBounds().top > sf::VideoMode::getDesktopMode().height)
		{
			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}
		++counter;

		//std::cout << "Number of enemies: " << this->enemies.size() << "\n";	// Shows number of enemy instances
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_removed = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_removed == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_removed = true;
			}
		}
	}
}

void Game::update()
{
	// TODO: Update player velocity


	this->updatePollEvents();
	this->updateInput();

	this->player->update();

	this->updateBullets();

	this->updateEnemies();
		
	this->updateCombat();

	this->updateGUI();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

void Game::render()
{
	// Clear last frame
	this->window->clear();

	// Draw all the objects
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->player->render(*this->window);

	this->renderGUI();

	// Show new frame
	this->window->display();
}
