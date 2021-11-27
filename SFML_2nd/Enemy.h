#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

class Enemy
{
private:
	// Shape
	sf::CircleShape shape;

	// Variables
	int type;
	int hp;
	int hpMax;
	float speed;
	int damage;
	int points;

	
	// Private functions
	void initShape();
	void initVariables();

public:
	// Constructors / Deconstructors
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;

	// Functions
	void update();
	void render(sf::RenderTarget* target);

};

#endif // !EMENY_H

