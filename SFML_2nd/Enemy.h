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
	unsigned pointCount;
	int type;
	int hp;
	int hpMax;
	int speed;
	int damage;
	int scrap;
	int lastType;

	
	// Private functions
	void initShape();
	void initVariables();

public:
	// Constructors / Deconstructors
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getScrap() const;

	// Modifiers
	void setType(const int _type);

	// Functions
	void update();
	void updateStats();
	void render(sf::RenderTarget* target);

};

#endif // !EMENY_H

