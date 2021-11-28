#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 13 + 3; // min = 3 max = 15
	this->speed = static_cast<float>(this->pointCount);
	this->scrap = static_cast<int>(this->pointCount);
	this->type = 0;
	this->hpMax = this->pointCount;
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
}

void Enemy::initShape()
{
	// Create the shape of the enemy
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}
// Constructors / Deconstructors
Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();

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

const int& Enemy::getScrap() const
{
	return this->scrap;
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

