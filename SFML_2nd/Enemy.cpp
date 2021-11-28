#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 4 + 3;	// min = 3 max = 6
	this->speed = rand() % 6 + 5;	// min = 5 max = 10
	this->hpMax = rand() % 21 + 20; // min = 20 max = 40
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	this->scrap = (this->pointCount + this->speed + this->hpMax / 3) / 2;
	this->lastType = 0;
	std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
}

void Enemy::initShape()
{
	// Create the shape of the enemy
	this->shape.setRadius(this->hpMax);
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

void Enemy::setType(const int _type)
{
	this->type = _type;
}

// Functions
void Enemy::update()
{
	this->shape.move(0.f, this->speed);

	this->updateStats();
}

void Enemy::updateStats()
{
	
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

