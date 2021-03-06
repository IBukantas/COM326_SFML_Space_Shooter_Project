#include "Game.h"

// Private functions
void Game::initWindow() {
	// Create window
	this->window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Game", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures() {
	//Load bullet textures
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("images/projectile_image.png");
}

void Game::initGUI() {
	// Load font
	if (!this->font.loadFromFile("fonts/arial.ttf")) {
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	}

	// Initialise scrap text
	this->scrapText.setPosition(sf::Vector2f(20.f, 50.f));
	this->scrapText.setFont(this->font);
	this->scrapText.setCharacterSize(24);
	this->scrapText.setFillColor(sf::Color::White);

	// Initialise lost game text
	this->lostText.setFont(this->font);
	this->lostText.setString("YOU GAME ENDED!!!");
	this->lostText.setCharacterSize(160);
	this->lostText.setPosition(
		sf::Vector2f(
			sf::VideoMode::getDesktopMode().width / 2 - this->lostText.getGlobalBounds().width / 2,
			sf::VideoMode::getDesktopMode().height / 2 - this->lostText.getGlobalBounds().height * 2
		));
	this->lostText.setFillColor(sf::Color::Transparent);

	// Initialise final score text
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(80);
	this->scoreText.setFillColor(sf::Color::Transparent);

	// Initialise Player Health GUI
	this->playerHPBar.setSize(sf::Vector2f(400.f, 20.f));
	this->playerHPBar.setPosition(sf::Vector2f(20.f, 20.f));
	this->playerHPBar.setOutlineColor(sf::Color(200, 200, 200, 200));

	this->playerHPBarBack = this->playerHPBar;

	this->playerHPBar.setFillColor(sf::Color(196, 39, 27, 240));
	this->playerHPBarBack.setFillColor(sf::Color(100, 100, 100, 150));
	this->playerHPBarBack.setOutlineThickness(2.f);

	// Initialise show controls text
	this->showText.setFont(this->font);
	this->showText.setCharacterSize(36);
	this->showText.setString("Press 'P' to pause game");
	this->showText.setOrigin(this->showText.getGlobalBounds().width, this->showText.getGlobalBounds().height);
	this->showText.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 20, sf::VideoMode::getDesktopMode().height - 20));
	this->showText.setFillColor(sf::Color::White);

	// Initialise control instruction text
	this->controlsText.setFont(this->font);
	this->controlsText.setCharacterSize(24);
	this->controlsText.setString("Controls:\nPress 'W' to move up\nPress 'S' to move down\nPress 'A' to move left\nPress 'D' to move right\nLeft mouse button will shoot pellot - Use this to destroy enemies!\nRight mouse button will turn your health into scrap/pellots - Useful if you run out of scrap! *But can kill you if health runs out*\nPress space bar to convert scrap into health - This one's a real life saver!\nPress '-' to lower music volume and '+' to increase music volume\nPress 'Divide' to lower effect volume and 'Multiply' to increase effect volume\n\nPress 'P' to start/pause the game\n\nPress 'Escape' to quit the game window");
	this->controlsText.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - this->controlsText.getGlobalBounds().width / 2, sf::VideoMode::getDesktopMode().height / 2 - this->controlsText.getGlobalBounds().height / 2));
	this->controlsText.setFillColor(sf::Color::White);

	// Initialise quit window text
	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(36);
	this->quitText.setString("Press 'Escape' to quit game");
	this->quitText.setOrigin(this->quitText.getGlobalBounds().width, this->quitText.getGlobalBounds().height);
	this->quitText.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 20, sf::VideoMode::getDesktopMode().height - 20));
	this->quitText.setFillColor(sf::Color::White);
}

void Game::initWorld() {
	// Load world background file
	if (!this->starsBackground.loadFromFile("images/stars_texture.png")) {
		std::cout << "ERROR::GAME::Could not load stars background texture" << "\n";
	}
	if (!this->galaxyBackground.loadFromFile("images/galaxy.png")) {
		std::cout << "ERROR::GAME::Could not load Galaxy background texture" << "\n";
	}

	// Initialise background textures
	this->worldBackground.setTexture(this->starsBackground);
	this->galaxySprite.setTexture(this->galaxyBackground);

	// Initialise background properties
	this->galaxySprite.setOrigin(this->galaxySprite.getGlobalBounds().width /2, this->galaxySprite.getGlobalBounds().height /2);
	this->galaxySprite.setPosition(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
	
}

void Game::initSystems() {
	// Initialise paused variable at start of game
	this->paused = true;

	// Initialise player's scrap at start of game
	this->scrap = 10;

	// Initialise difficulty type at start of game
	this->currentType = 0;

	// Initialise final game over play check
	this->soundPlayed = false;
}

void Game::initPlayer() {
	// Create player
	this->player = new Player();
}

void Game::initEnemies() {
	// Initialise enemy variables
	this->currentType = 0;
	this->spawnTimerMax = 25.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initMusic() {
	// Load music from files
	if (!musicBackground.openFromFile(".\\audio\\background_song.ogg")) {
		std::cout << "ERROR::GAME::Failed to load background music" << "\n";
	}

	if (!musicMenu.openFromFile(".\\audio\\menu_music.ogg")) {
		std::cout << "ERROR::GAME::Failed to load menu music" << "\n";
	}

	// Initialise music properties
	this->musicMenu.play();
	this->gameVolume = 10.f;
	this->musicBackground.setVolume(this->gameVolume);
	this->musicBackground.setLoop(true);
	this->musicMenu.setVolume(this->gameVolume);
	this->musicMenu.setLoop(true);
}

void Game::initSounds() {
	// Load sound effects from file
	if (!bufferGameOver.loadFromFile(".\\audio\\game_over.ogg")) {
		std::cout << "ERROR::GAME::Failed to load game over sound" << "\n";
	}

	if (!bufferGunShot.loadFromFile(".\\audio\\gun_shot.ogg")) {
		std::cout << "ERROR::GAME::Failed to load gun shot sound" << "\n";
	}

	if (!bufferHitSound.loadFromFile(".\\audio\\hit_sound.ogg")) {
		std::cout << "ERROR::GAME::Failed to load hit sound" << "\n";
	}

	if (!bufferKillSound.loadFromFile(".\\audio\\kill_sound.ogg")) {
		std::cout << "ERROR::GAME::Failed to load kill sound" << "\n";
	}

	if (!bufferHealingSound.loadFromFile(".\\audio\\healing_sound.ogg")) {
		std::cout << "ERROR::GAME::Failed to load healing sound" << "\n";
	}

	if (!bufferScrappingSound.loadFromFile(".\\audio\\scrapping_sound.ogg")) {
		std::cout << "ERROR::GAME::Failed to load scrapping sound" << "\n";
	}

	if (!bufferMenuIn.loadFromFile(".\\audio\\menu_in.ogg")) {
		std::cout << "ERROR::GAME::Failed to load menu in sound" << "\n";
	}

	if (!bufferMenuOut.loadFromFile(".\\audio\\menu_out.ogg")) {
		std::cout << "ERROR::GAME::Failed to load menu out sound" << "\n";
	}

	if (!bufferPlayerHit.loadFromFile(".\\audio\\player_hit.ogg")) {
		std::cout << "ERROR::GAME::Failed to load player hit sound" << "\n";
	}

	if (!bufferAdjustSound.loadFromFile(".\\audio\\adjust_sound.ogg")) {
		std::cout << "ERROR::GAME::Failed to load adjust sound" << "\n";
	}

	// Initialise sound effect properties
	this->effectVolume = 10.f;
	this->sound.setVolume(this->effectVolume);
	this->soundHitSound.setVolume(this->effectVolume);
	this->soundMenu.setVolume(this->effectVolume);
	this->soundAdjustSound.setVolume(this->effectVolume);
	this->soundPlayerHit.setVolume(this->effectVolume);
	this->soundKillSound.setVolume(this->effectVolume);
	this->soundHealthBarSound.setVolume(this->effectVolume);
	this->soundGameOver.setVolume(this->effectVolume);
	this->soundShot.setVolume(this->effectVolume);
}



// Constructors / Deconstructors
Game::Game() {
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
	this->initMusic();
	this->initSounds();
}

Game::~Game() {
	delete this->window;
	delete this->player;

	// Delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}

	// Delete bullets
	for (auto* i : this->bullets) {
		delete i;
	}

	// Delete enemies
	for (auto* i : this->enemies) {
		delete i;
	}
}

// Functions
void Game::run() {
	// While window is open, update new frames 
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::updatePollEvents() {
	// Check for events 
	sf::Event e;
	while (this->window->pollEvent(e)) {
		// When "Escape" is pressed end game
		if (e.type == sf::Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
			this->window->close();
		}

		// When "P" is pressed pause game
		if (e.type == sf::Event::KeyReleased && e.Event::key.code == sf::Keyboard::P) {
			if (this->paused == true) {
				this->musicMenu.stop();
				this->musicBackground.play();
				this->soundMenu.setBuffer(this->bufferMenuOut);
				this->soundMenu.play();
				this->paused = false;
			}
			else {
				this->musicBackground.stop();
				this->musicMenu.play();
				this->soundMenu.setBuffer(this->bufferMenuIn);
				this->soundMenu.play();
				this->paused = true;
			}
		}

		// Adjust background music volume
		if (e.type == sf::Event::KeyPressed && e.Event::key.code == sf::Keyboard::Add && this->gameVolume < 100.f) {
			this->gameVolume += 10.f;
			this->musicBackground.setVolume(this->gameVolume);
			this->musicMenu.setVolume(this->gameVolume);

			this->soundAdjustSound.setBuffer(this->bufferAdjustSound);
			this->soundAdjustSound.play();
		}

		if (e.type == sf::Event::KeyPressed && e.Event::key.code == sf::Keyboard::Subtract && this->gameVolume > 0.f) {
			this->gameVolume -= 10.f;
			this->musicBackground.setVolume(this->gameVolume);
			this->musicMenu.setVolume(this->gameVolume);

			this->soundAdjustSound.setBuffer(this->bufferAdjustSound);
			this->soundAdjustSound.play();
		}

		// Adjust sound effect volume
		if (e.type == sf::Event::KeyPressed && e.Event::key.code == sf::Keyboard::Multiply && this->effectVolume < 100.f) {
			this->effectVolume += 10.f;
			this->sound.setVolume(this->effectVolume);
			this->soundHitSound.setVolume(this->effectVolume);
			this->soundMenu.setVolume(this->effectVolume);
			this->soundAdjustSound.setVolume(this->effectVolume);
			this->soundPlayerHit.setVolume(this->effectVolume);
			this->soundKillSound.setVolume(this->effectVolume);
			this->soundHealthBarSound.setVolume(this->effectVolume);
			this->soundGameOver.setVolume(this->effectVolume);
			this->soundShot.setVolume(this->effectVolume);

			this->soundAdjustSound.setBuffer(this->bufferAdjustSound);
			this->soundAdjustSound.play();
		}

		if (e.type == sf::Event::KeyPressed && e.Event::key.code == sf::Keyboard::Divide && this->effectVolume > 0.f){
			this->effectVolume -= 10.f;
			this->sound.setVolume(this->effectVolume);
			this->soundHitSound.setVolume(this->effectVolume);
			this->soundMenu.setVolume(this->effectVolume);
			this->soundAdjustSound.setVolume(this->effectVolume);
			this->soundPlayerHit.setVolume(this->effectVolume);
			this->soundKillSound.setVolume(this->effectVolume);
			this->soundHealthBarSound.setVolume(this->effectVolume);
			this->soundGameOver.setVolume(this->effectVolume);
			this->soundShot.setVolume(this->effectVolume);

			this->soundAdjustSound.setBuffer(this->bufferAdjustSound);
			this->soundAdjustSound.play();
		}
	}
}

void Game::updateInput() {
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->player->move(0, 1.f);
	}

	// When "Space Bar" is pressed convert scrap to health
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->scrap > 1) {
		if (this->player->getPlayerHealth() < this->player->getMaxHealth()) {
			this->player->loseHealth(-1);
		}

		this->soundHealthBarSound.setBuffer(this->bufferHealingSound);
		this->soundHealthBarSound.play();

		this->scrap -= 2;
	}
	// When right mouse button is pressed convert health to scrap
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->player->getPlayerHealth() > 0) {
		this->soundHealthBarSound.setBuffer(this->bufferScrappingSound);
		this->soundHealthBarSound.play();

		this->scrap += 2;

		this->player->loseHealth(1);
	}

	// When left mouse button is pressed create new bullet
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack() && scrap > 0) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 15.f));

		this->soundShot.setBuffer(bufferGunShot);
		this->soundShot.play();

		this->scrap--;
	}
}

void Game::updateGUI() {
	// Create new sting streams
	std::stringstream ss;
	std::stringstream ssp2;

	ss << "Scrap: " << this->scrap;

	ssp2 << "Your Final Score: " << this->scrap;

	this->scrapText.setString(ss.str());

	this->scoreText.setString(ssp2.str());

	// Set position of text
	this->scoreText.setPosition(
		sf::Vector2f(
			this->lostText.getGlobalBounds().left + 40.f,
			sf::VideoMode::getDesktopMode().height / 2
		));

	// Update Health Bar to match player's health
	if (this->playerHPBar.getSize().x > 0.f) {
		this->playerHPBar.setSize(sf::Vector2f(static_cast<float>(this->player->getPlayerHealth() * 20), 20.f));
	}
	else {

		this->lostText.setFillColor(sf::Color::White);

		this->scoreText.setFillColor(sf::Color::White);
	}
}

void Game::updateWorld() {
	// Animate galaxy background
	this->currentRotation = this->galaxySprite.getRotation();
	this->galaxySprite.setRotation(this->currentRotation += 0.01f);
}

void Game::updateCollision() {
	// left and right player world collision
	if (this->player->getBounds().left < -this->player->getBounds().width / 2) {
		this->player->setPosition(-this->player->getBounds().width / 2 + (this->player->getBounds().width / 2), this->player->getBounds().top);
	}
	else if (this->player->getBounds().left + this->player->getBounds().width > sf::VideoMode::getDesktopMode().width + this->player->getBounds().width / 2) {
		this->player->setPosition(sf::VideoMode::getDesktopMode().width, this->player->getBounds().top);
	}
	// top and bottom player world collision
	if (this->player->getBounds().top < 0.f) {
		this->player->setPosition(this->player->getBounds().left + this->player->getBounds().width / 2, 0);
	}
	else if (this->player->getBounds().top + this->player->getBounds().height / 2 > sf::VideoMode::getDesktopMode().height) {
		this->player->setPosition(this->player->getBounds().left + this->player->getBounds().width / 2, sf::VideoMode::getDesktopMode().height - this->player->getBounds().height / 2);
	}
}

void Game::updateBullets() {
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->update();

		// Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			// Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateEnemies() {
	// Spawning
	this->spawnTimer += 0.5f;

	if (this->scrap > 100 && this->currentType == 0) {
		this->spawnTimerMax -= 3;
		this->currentType++;
		this->player->setSprite(this->currentType);
	}
	else if (this->scrap > 500 && this->currentType == 1) {
		this->spawnTimerMax -= 3;
		this->currentType++;
	}
	else if (this->scrap > 1000 && this->currentType == 2) {
		this->spawnTimerMax -= 3;
		this->currentType++;
	}
	else if (this->scrap > 1700 && this->currentType == 3) {
		this->spawnTimerMax -= 3;
		this->currentType++;
	}
	else if (this->scrap > 3000 && this->currentType == 4) {
		this->spawnTimerMax -= 2;
		this->currentType++;
	}

	if (this->spawnTimer >= this->spawnTimerMax) {
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x, -300.f, this->currentType));

		this->spawnTimer = 0.f;
	}

	// Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update();

		// Enemy culling (top of screen)
		if (enemy->getBounds().top > sf::VideoMode::getDesktopMode().height) {
			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}
		// Enemy culling (left side of screen)
		if (enemy->getBounds().left < 0.f) {
			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}
		// Enemy culling (right side of screen)
		if (enemy->getBounds().left + enemy->getBounds().width > sf::VideoMode::getDesktopMode().width) {
			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}
		// Enemy culling (player contact)
		if (enemy->getBounds().intersects(this->player->getBounds())) {
			// Take away player health equal to enemy damage
			if (this->player->getPlayerHealth() >= enemy->getDamage()) {
				this->soundPlayerHit.setBuffer(bufferPlayerHit);
				this->soundPlayerHit.play();

				this->player->loseHealth(enemy->getDamage());
			}
			else {
				this->soundGameOver.setBuffer(bufferGameOver);
				this->soundGameOver.play();

				this->player->setHealth(0);
			}

			// Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateCombat() {
	// Update enemy and bullet collision
	for (int i = 0; i < this->enemies.size(); i++) {
		bool enemy_removed = false;

		for (size_t k = 0; k < this->bullets.size() && enemy_removed == false; k++) {
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {

				if (this->enemies[i]->getHP() <= 0) {
					this->soundKillSound.setBuffer(bufferKillSound);
					this->soundKillSound.play();
					this->scrap += this->enemies[i]->getScrap();
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);
				}
				else {
					this->soundHitSound.setBuffer(bufferHitSound);
					this->soundHitSound.play();

					this->enemies[i]->loseHP(this->player->getAttackDamage());
				}

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_removed = true;
			}
		}
	}
}

void Game::updateSounds() {
	// Update game over sound
	if (this->playerHPBar.getSize().x <= 0 && this->soundPlayed == false) {
		this->soundGameOver.setBuffer(bufferGameOver);
		this->soundGameOver.play();

		this->soundPlayed = true;
	}
}

void Game::update() {
	// Update poll events
	this->updatePollEvents();

	// Update gameplay objects when game is not paused and player is not dead
	if (this->paused == false) {
		if (this->playerHPBar.getSize().x > 0) {
			this->updateInput();

			this->updateWorld();

			this->player->update();

			this->updateCollision();

			this->updateBullets();

			this->updateEnemies();

			this->updateCombat();
		}
	}

	// Update update the rest of the objects
	this->updateSounds();

	this->updateGUI();
}

void Game::renderGUI() {
	// When paused render the control text
	if (this->paused == true) {
		this->window->draw(this->controlsText);
	}
	else {
		// When not paused check if player is dead
		if (this->playerHPBar.getSize().x > 0) {
			// When player is alive render gameplay objects 
			this->window->draw(this->scrapText);

			this->window->draw(this->playerHPBarBack);
			this->window->draw(this->playerHPBar);

			this->window->draw(this->showText);
		}
		else {
			// When player is dead render gameover objects 
			this->musicBackground.stop();

			this->window->draw(this->lostText);

			this->window->draw(this->scoreText);

			this->window->draw(this->quitText);
		}
	}
	
}

void Game::renderWorld() {
	// Render background objects
	this->window->draw(this->worldBackground);
	this->window->draw(this->galaxySprite);
}

void Game::render() {
	// Clear last frame
	this->window->clear();

	if (this->paused == false) {
		if (this->playerHPBar.getSize().x > 0) {
			// Draw world background
			this->renderWorld();

			// Draw all the objects
			for (auto* bullet : this->bullets) {
				bullet->render(this->window);
			}

			for (auto* enemy : this->enemies) {
				enemy->render(this->window);
			}

			this->player->render(*this->window);
		}
	}

	this->renderGUI();

	// Show new frame
	this->window->display();
}
