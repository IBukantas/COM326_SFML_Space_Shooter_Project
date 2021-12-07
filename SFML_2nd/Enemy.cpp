#include "Enemy.h"

void Enemy::initSprite() {
	// Load textures of player
	if (!enemyLT1.loadFromFile("images/largeEnemy1.png")) {
		std::cout << "ERROR::Player::Failed to load large enemy Texture 1" << "\n";
	}
	if (!enemyLT2.loadFromFile("images/largeEnemy2.png")) {
		std::cout << "ERROR::Player::Failed to load large enemy Texture 2" << "\n";
	}
	if (!enemyMT1.loadFromFile("images/medEnemy1.png")) {
		std::cout << "ERROR::Player::Failed to load medium enemy Texture 1" << "\n";
	}
	if (!enemyMT2.loadFromFile("images/medEnemy2.png")) {
		std::cout << "ERROR::Player::Failed to load medium enemy Texture 2" << "\n";
	}
	if (!enemyST1.loadFromFile("images/smallEnemy1.png")) {
		std::cout << "ERROR::Player::Failed to load small enemy Texture 1" << "\n";
	}
	if (!enemyST2.loadFromFile("images/smallEnemy2.png")) {
		std::cout << "ERROR::Player::Failed to load small enemy Texture 2" << "\n";
	}

	// Initialise Enemy sprite based on scrap amount
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
		if (rand() % 4 + 1 == 1) {
			this->enemySprite.setTexture(this->enemyMT1);
			this->enemySprite.setScale(2.f, 2.f);
		}
		else {
			this->enemySprite.setTexture(this->enemyMT2);
			this->enemySprite.setScale(2.f, 2.f);
		}
	}
	else if (this->scrap <= 52) {
		if (rand() % 2 + 1 == 1) {
			this->enemySprite.setTexture(this->enemyLT1);
			this->enemySprite.setScale(2.f, 2.f);
		}
		else {
			this->enemySprite.setTexture(this->enemyLT2);
			this->enemySprite.setScale(2.f, 2.f);
		}
	}

	// Initialise rotation
	this->enemySprite.setRotation(180.f);

}

void Enemy::initVariables() {
	// Initialise variables based on type
	if (this->type == 0) {
		this->hpMax = (rand() % 5 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 4 + 2);
		this->damage = 2;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type == 1) {
		this->hpMax = (rand() % 10 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 5 + 3);
		this->damage = 3;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type == 2) {
		this->hpMax = (rand() % 15 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 6 + 4);
		this->damage = 5;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type == 3) {
		this->hpMax = (rand() % 20 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 7 + 5);
		this->damage = 5;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type == 4) {
		this->hpMax = (rand() % 25 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 8 + 6);
		this->damage = (rand() % 3 + 5);
		this->scrap = this->hpMax + this->speed + this->damage;
	}
	else if (this->type == 5) {
		this->hpMax = (rand() % 30 + 2);
		this->hp = this->hpMax;
		this->speed = (rand() % 9 + 7);
		this->damage = (rand() % 6 + 5);;
		this->scrap = this->hpMax + this->speed + this->damage;
	}
}


// Constructors / Deconstructors
Enemy::Enemy(float pos_x, float pos_y, int _type) {
	this->type = _type;

	this->initVariables();

	this->initSprite();

	this->enemySprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() {

}

// Accessors
const sf::FloatRect Enemy::getBounds() const {
	// Return global bounds
	return this->enemySprite.getGlobalBounds();
}

const int& Enemy::getScrap() const {
	// Return scrap
	return this->scrap;
}

const int& Enemy::getDamage() const {
	// Return damage
	return this->damage;
}

const int& Enemy::getHP() const {
	// Return return current hp
	return this->hp;
}

// Modifiers
void Enemy::loseHP(const int value) {
	// Set health
	this->hp -= value;
}

// Functions
void Enemy::update() {
	// Movement
	this->enemySprite.move(0.f, this->speed);

}

void Enemy::render(sf::RenderTarget* target) {
	// draw enemy to target
	target->draw(this->enemySprite);
}

