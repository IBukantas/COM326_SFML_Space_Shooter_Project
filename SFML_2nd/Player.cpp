#include "Player.h"

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 12.f;	// Not used for anything rn

	this->maxHealth = 20;
	this->playerHealth = this->maxHealth;

	this->playerSize = this->playerHealth * 2;

	this->attackDamage = 10;

	this->attackCooldownMax = 8.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initShape()
{
	// Create the shape of the player
	this->playerShape.setRadius(this->playerSize);
	this->playerShape.setOrigin(this->playerSize, this->playerSize);
	this->playerShape.setPosition(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 200);
}

// Constructors / Deconstructors
Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

// Accessors
const sf::Vector2f& Player::getPos() const
{
	// TODO: insert return statement here
	return this->playerShape.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerShape.getGlobalBounds();
}

const int& Player::getMaxHealth() const
{
	return this->maxHealth;
}

const int& Player::getPlayerHealth() const
{
	return this->playerHealth;
}

const int& Player::getAttackDamage() const
{
	return this->attackDamage;
}

// Modifiers
void Player::setPosition(const float x, const float y)
{
	this->playerShape.setPosition(x, y);
}

void Player::setRadius(const float r)
{
	this->playerShape.setRadius(r);
}

void Player::setHealth(const int health)
{
	this->playerHealth = health;
}

void Player::loseHealth(const int value)
{
	this->playerHealth -= value;
}

// Functions
void Player::move(const float dirX, const float dirY)
{
	this->playerShape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	else
	{
		return false;
	}
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 1.f;
	}
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerShape);
}
