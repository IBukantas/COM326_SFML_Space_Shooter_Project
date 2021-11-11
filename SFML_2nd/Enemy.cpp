#include "Enemy.h"

void Enemy::initShape()
{
	// Create the shaoe of the enemy
	this->shape.setRadius(rand()% 50 + 20);
	this->shape.setPointCount(rand()% 10 + 3);
}

void Enemy::initVariables()
{
	this->type = 0;
	this->hpMax = this->shape.getRadius();
	this->hp = 0;
	this->damage = this->shape.getPointCount();
	this->points = shape.getRadius() + shape.getPointCount() / 5;
	std::cout << "Enemy worth: " << points << " points" << std::endl;
}

// Constructors / Deconstructors
Enemy::Enemy(float pos_x, float pos_y)
{
	this->initShape();
	this->initVariables();

	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

// Functions
void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

