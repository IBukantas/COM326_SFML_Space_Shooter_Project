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

	// World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	// Systems
	unsigned scrap;

	// Player
	Player* player;

	// Enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

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
	void update();
	
	void renderGUI();
	void renderWorld();
	void render();
};

#endif // !GAME_H
