#include "Enemy.h"

void Enemy::initVariables()
{
	if (this->type == 0)
	{
		this->maxValue = 10;
		this->speed = (rand() % 3 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->pointCount = (rand() % 2 + 3);			// max = 4
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 16 - this->speed;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
	else if (this->type == 1)
	{
		this->maxValue = 10;
		this->pointCount = (rand() % 3 + 3);	// max = 5
		this->speed = (rand() % 4 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 12 - this->speed * 2;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
	else if (this->type == 2)
	{
		this->maxValue = 20;
		this->pointCount = (rand() % 4 + 3);	// max = 6
		this->speed = (rand() % 6 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 4 - this->speed * 2;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
	else if (this->type == 3)
	{
		this->maxValue = 20;
		this->pointCount = (rand() % 4 + 4);	// max = 7
		this->speed = (rand() % 8 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 5 - this->speed * 2;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
	else if (this->type == 4)
	{
		this->maxValue = 30;
		this->pointCount = (rand() % 5 + 4);	// max = 8
		this->speed = (rand() % 10 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 3 - this->speed * 2;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
	else if (this->type == 5)
	{
		this->maxValue = 30;
		this->pointCount = (rand() % 6 + 5);	// max = 10
		this->speed = (rand() % 12 + 1);						// max = 3
		this->leftValue = this->maxValue - this->speed;
		this->hpMax = this->leftValue;
		this->hp = this->hpMax;
		this->damage = this->pointCount;
		this->scrap = this->pointCount + this->speed + this->hpMax / 2;
		this->leftValue = this->leftValue * 2 - this->speed;
		std::cout << "Enemy worth: " << scrap << " scrap" << std::endl;
	}
}

void Enemy::initShape()
{
	// Create the shape of the enemy
	this->shape.setRadius(this->leftValue);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}
// Constructors / Deconstructors
Enemy::Enemy(float pos_x, float pos_y, int _type)
{
	this->type = _type;

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

// Modifiers
void Enemy::loseHP(const int value)
{
	this->hp -= value;
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

