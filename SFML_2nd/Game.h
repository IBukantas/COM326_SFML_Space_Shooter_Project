#ifndef GAME_H
#define GAME_H

#include<map>

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
	void updateBullets();
	void updateEnemiesAndCombat();
	void update();
	void render();
};

#endif // !GAME_H
