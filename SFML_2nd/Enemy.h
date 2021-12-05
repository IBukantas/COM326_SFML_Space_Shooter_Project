#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

class Enemy
{
private:
	
	// Sprite
	sf::Texture enemyLT1;
	sf::Texture enemyLT2;
	sf::Texture enemyMT1;
	sf::Texture enemyMT2;
	sf::Texture enemyST1;
	sf::Texture enemyST2;
	sf::Sprite enemySprite;

	// Variables
	
	int type;
	int hp;
	int hpMax;
	int speed;
	int damage;
	int scrap;
	int maxValue;
	int leftValue;

	
	// Private functions
	void initSprite();
	void initVariables();

public:
	// Constructors / Deconstructors
	Enemy(float pos_x, float pos_y, int _type);
	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getScrap() const;
	const int& getDamage() const;
	const int& getHP() const;

	// Modifiers
	void loseHP(const int value);

	// Functions
	void update();
	void render(sf::RenderTarget* target);

};

#endif // !EMENY_H

