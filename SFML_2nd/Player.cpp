#include "Player.h"

// Private functions
void Player::initVariables()
{
	this->movementSpeed = 12.f;

	this->maxHealth = 20;
	this->playerHealth = this->maxHealth;

	this->playerSize = this->playerHealth * 2;

	this->attackDamage = 10;

	this->attackCooldownMax = 8.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initSprite()
{
	// load textures of player
	if (!playerT1.loadFromFile("images/player3.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 1" << "\n";
	}
	if (!playerT2.loadFromFile("images/player2.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 2" << "\n";
	}
	if (!playerT3.loadFromFile("images/player1.png"))
	{
		std::cout << "ERROR::Player::Failed to player Texture 3" << "\n";
	}

	this->playerSprite.setTexture(this->playerT1);

	this->playerSprite.setPosition(sf::VideoMode::getDesktopMode().width /2,sf::VideoMode::getDesktopMode().height /1.5f);
	this->playerSprite.setScale(2, 2);
	this->playerSprite.setOrigin(this->playerSprite.getGlobalBounds().width /4, 0);
}

// Constructors / Deconstructors
Player::Player()
{
	this->initVariables();
	this->initSprite();
}

Player::~Player()
{

}

// Accessors
const sf::Vector2f& Player::getPos() const
{
	// Return player's position
	return this->playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	// Return player's global bounds
	return this->playerSprite.getGlobalBounds();
}

const int& Player::getMaxHealth() const
{
	// Return player's max health
	return this->maxHealth;
}

const int& Player::getPlayerHealth() const
{
	// Return player's current health
	return this->playerHealth;
}

const int& Player::getAttackDamage() const
{
	// Return player's attack damage
	return this->attackDamage;
}

// Modifiers
void Player::setPosition(const float x, const float y)
{
	// Set player's position
	this->playerSprite.setPosition(x, y);
}

void Player::setSprite(const int currentStage)
{
	// Set player's player's sprite
	if(currentStage == 2){
		this->playerSprite.setTexture(this->playerT2);
	}
	if (currentStage == 4) {
		this->playerSprite.setTexture(this->playerT3);
	}
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
	this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
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
	target.draw(this->playerSprite);
}
