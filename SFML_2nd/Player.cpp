#include "Player.h"

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 10.f;	// Not used for anything rn
	this->playerHealth = 30;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initShape()
{
	// Create the shape of the player
	this->playerShape.setRadius(this->playerHealth);
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

void Player::updateDamage()
{
	// When damage is taken, decrease player's health
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && playerHealth > 0)
	{
		this->playerHealth = this->playerHealth - 1;
	}
	else
	{
		;	// When health = 0 die :)
	}

	// Update player's size
	this->playerShape.setRadius(this->playerHealth);
}

void Player::update()
{
	this->updateAttack();
	this->updateDamage();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerShape);
}
