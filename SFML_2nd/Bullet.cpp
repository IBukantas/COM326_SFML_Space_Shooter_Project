#include "Bullet.h"

// Constructors / Deconstructors
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed) {
	this->shape.setTexture(*texture);
	this->shape.setScale(0.05, 0.05);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);

	this->shape.setPosition(pos_x - this->shape.getGlobalBounds().width / 2, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet() {

}

// Accessor
sf::FloatRect Bullet::getBounds() const {
	// Return global bounds
	return this->shape.getGlobalBounds();
}

// Functions
void Bullet::update() {
	// Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target) {
	// draw bullet on target
	target->draw(this->shape);
}

