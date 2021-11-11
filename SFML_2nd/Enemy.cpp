#include "Enemy.h"

// Private functions
void Enemy::initTexture()
{
	// Load a texture from a file
	
	if (!this->texture.loadFromFile("images/enemy_image.png"))
	{
		std::cout << "Error: Enemy: InitTexture: Could not load texture file" << std::endl;
	}
}

void Enemy::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Resize the sprite
	this->sprite.scale(1.f, 1.f);

	// Center the origin of the player
	this->sprite.setOrigin(15.f, 0.f);
}

void Enemy::initVariables()
{
	switch (type)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}
	this->sprite.setPosition(20.f, 20.f);

	this->type = rand() % 5;
	this->hpMax = 100;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
}

// Constructors / Deconstructors
Enemy::Enemy()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Enemy::~Enemy()
{

}

// Functions
void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

