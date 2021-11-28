#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

class Player
{
private:
	// Sprite
	sf::CircleShape playerShape;

	// Variables
	float movementSpeed;
	int playerHealth;

	float attackCooldown;
	float attackCooldownMax;

	// Private functions
	void initShape();
	void initVariables();

public:
	// Constructors / Deconstructors
	Player();
	virtual ~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	// Modifiers
	void setPosition(const float x, const float y);
	void setRadius(const float r);


	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H