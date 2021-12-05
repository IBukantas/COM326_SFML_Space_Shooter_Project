#include "Enemy.h"

void Enemy::initSprite()
{
	// load textures of player
	if (!enemyLT1.loadFromFile("images/largeEnemy1.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 1" << "\n";
	}
	if (!enemyLT2.loadFromFile("images/largeEnemy2.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 2" << "\n";
	}
	if (!enemyMT1.loadFromFile("images/medEnemy1.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 3" << "\n";
	}
	if (!enemyMT2.loadFromFile("images/medEnemy2.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 3" << "\n";
	}
	if (!enemyST1.loadFromFile("images/smallEnemy1.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 3" << "\n";
	}
	if (!enemyST2.loadFromFile("images/smallEnemy2.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 3" << "\n";
	}
	
	if (this->scrap <= 14) {
		if (rand() % 2 + 1 == 1) {
			this->enemySprite.setTexture(this->enemyST1);
			this->enemySprite.setScale(2.f, 2.f);
		}
		else {
			this->enemySprite.setTexture(this->enemyST2);
			this->enemySprite.setScale(2.f, 2.f);
		}
	}
	else if (this->scrap <= 31) {
		this->enemySprite.setTexture(this->enemyMT1);
	}

	this->enemySprite.setRotation(180.f);
	
}

void Enemy::initVariables()
{
	if (this->type == 0) {
		this->hpMax = (rand() % 5 + 2);
		this->hp=this->hpMax;
		this->speed = (rand() % 5 + 2);
		this->damage = 2;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type = 1) {
		this->hpMax = (rand() % 10 + 5);
		this->hp = this->hpMax;
		this->speed = (rand() % 10 + 5);
		this->damage = 3;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
}


// Constructors / Deconstructors
Enemy::Enemy(float pos_x, float pos_y, int _type)
{
	this->type = _type;

	this->initVariables();

	this->initSprite();

	this->enemySprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

// Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
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
	this->enemySprite.move(0.f, this->speed);

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->enemySprite);
}

