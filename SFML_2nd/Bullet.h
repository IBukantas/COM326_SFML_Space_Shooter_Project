#ifndef BULLET_H
#define BULLET_H

#include<iostream>

#include<SFML/Graphics.hpp>

class Bullet {
private:
	// Sprite
	sf::Sprite shape;

	// Variables
	sf::Vector2f direction;
	float movementSpeed;

public:
	// Constructors / Deconstructors
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	// Accessor
	sf::FloatRect getBounds() const;

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H

