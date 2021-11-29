#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 3 + 3;	// min = 3 max = 5
	this->speed = rand() % 4 + 2;	// min = 2 max = 5
	this->hpMax = rand() % 11 + 5; // min = 5 max = 15
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	this->scrap = (this->pointCount + this->speed + this->hpMax / 2) / 2;
	this->lastType = 0;
	std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
}

void Enemy::initShape()
{
	// Create the shape of the enemy
	this->shape.setRadius(this->pointCount * 10);
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

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getHP() const
{
	return this->hp;
}

void Enemy::setType(const int _type)
{
	this->type = _type;
}

void Enemy::loseHP(const int value)
{
	this->hp -= value;
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

