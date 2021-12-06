#ifndef GAME_H
#define GAME_H

#include<map>
#include<string>
#include<sstream>

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "HUDText.h"

class Game
{
private:
	// Clock
	sf::Clock clock;

	// Window
	sf::RenderWindow* window;

	// Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text scrapText;
	sf::Text lostText;
	sf::Text scoreText;
	sf::Text showText;
	sf::Text controlsText;
	sf::Text quitText;

	// World
	sf::Texture starsBackground;
	sf::Sprite worldBackground;
	sf::Texture galaxyBackground;
	sf::Sprite galaxySprite;
	float currentRotation;

	// Systems
	bool paused;
	unsigned scrap;
	unsigned currentType;

	// Player
	Player* player;

	// Player GUI
	sf::RectangleShape playerHPBar;
	sf::RectangleShape playerHPBarBack;

	// Enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	// Music
	sf::Music musicBackground;
	sf::Music musicMenu;
	float gameVolume;

	// Sounds
	sf::SoundBuffer bufferGameOver;
	sf::SoundBuffer bufferGunShot;
	sf::SoundBuffer bufferHitSound;
	sf::SoundBuffer bufferKillSound;
	sf::SoundBuffer bufferHealingSound;
	sf::SoundBuffer bufferScrappingSound;
	sf::SoundBuffer bufferMenuIn;
	sf::SoundBuffer bufferMenuOut;
	sf::SoundBuffer bufferAdjustSound;
	sf::SoundBuffer bufferPlayerHit;
	sf::Sound sound;
	sf::Sound soundHitSound;
	sf::Sound soundMenu;
	sf::Sound soundAdjustSound;
	sf::Sound soundPlayerHit;
	sf::Sound soundKillSound;
	sf::Sound soundHealthBarSound;
	sf::Sound soundGameOver;
	sf::Sound soundShot;
	float effectVolume;
	bool soundPlayed;

	// Mouse positions
	sf::Vector2i mousePosWindow;

	// Private Functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();
	void initMusic();
	void initSounds();

public:
	// Constructors / Deconstructors
	Game();
	virtual ~Game();

	// Functions
	void run();

	void updateMousePositions();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void updateSounds();
	void update();
	
	void renderGUI();
	void renderWorld();
	void render();
};

#endif // !GAME_H
