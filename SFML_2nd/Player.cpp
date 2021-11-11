#include "Player.h"

// Private functions
void Player::initTexture()
{
	// Load a texture from a file
	if (!this->texture.loadFromFile("images/player_image.png"))
	{
		std::cout << "Error: Player: InitTexture: Could not load texture file" << std::endl;
	}
}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Resize the sprite
	this->sprite.scale(1.f, 1.f);

	// Center the origin of the player
	this->sprite.setOrigin(15.f, 0.f);
}

void Player::initVariables()
{
	this->movementSpeed = 10.f;	// Not used for anything rn
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

}



// Constructors / Deconstructors
Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Player::~Player()
{

}

// Accessors
const sf::Vector2f& Player::getPos() const
{
	// TODO: insert return statement here
	return this->sprite.getPosition();
}

// Functions
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
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
	target.draw(this->sprite);
}
