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

	int maxHealth;
	int playerHealth;

	int playerSize;

	int attackDamage;

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
	const int& getMaxHealth() const;
	const int& getPlayerHealth() const;
	const int& getAttackDamage() const;

	// Modifiers
	void setPosition(const float x, const float y);
	void setRadius(const float r);
	void setHealth(const int health);
	void loseHealth(const int value);


	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H