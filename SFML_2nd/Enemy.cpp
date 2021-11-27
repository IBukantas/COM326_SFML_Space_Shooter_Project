#include "Enemy.h"

void Enemy::initShape()
{
	// Create the shape of the enemy
	this->shape.setRadius(rand()% 40 + 20);
	this->shape.setPointCount(rand()% 10 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Enemy::initVariables()
{
	this->type = 0;
	this->hpMax = this->shape.getRadius();
	this->hp = 0;
	this->speed = (62 - this->shape.getRadius()) / 3;
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

// Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

// Functions
void Enemy::update()
{
	this->shape.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

