#include "Player.h"

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 20.f;	// Not used for anything rn
	this->playerHealth = 40;
	this->attackCooldownMax = 6.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initShape()
{
	// Create the shape of the player
	this->playerShape.setRadius(this->playerHealth);
	this->playerShape.setOrigin(this->playerHealth, this->playerHealth);
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
