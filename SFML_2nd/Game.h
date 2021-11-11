#ifndef GAME_H
#define GAME_H

#include<map>

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Game
{
private:
	// Window
	sf::RenderWindow* window;

	// Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	// Player
	Player* player;
	Enemy* enemy;

	// Mouse positions
	sf::Vector2i mousePosWindow;

	// Private Functions
	void initWindow();
	void initTextures();

	void initPlayer();
	void initEnemy();

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
	void update();
	void render();
};

#endif // !GAME_H
