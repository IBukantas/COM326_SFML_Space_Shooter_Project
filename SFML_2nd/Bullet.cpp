#include "Bullet.h"

// Constructors / Deconstructors
Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(2.f, 2.f);
	this->shape.setOrigin(3, 3);

	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

// Accessor
sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

// Functions
void Bullet::update()
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

