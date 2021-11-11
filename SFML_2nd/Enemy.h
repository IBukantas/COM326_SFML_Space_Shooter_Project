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
	sf::Sprite sprite;
	sf::Texture texture;

	// Variables
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	
	// Private functions
	void initTexture();
	void initSprite();
	void initVariables();

public:
	// Constructors / Deconstructors
	Enemy();
	virtual ~Enemy();

	// Functions
	void update();
	void render(sf::RenderTarget& target);

};

#endif // !EMENY_H

