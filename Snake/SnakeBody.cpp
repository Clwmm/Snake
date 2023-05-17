#include "SnakeBody.h"

SnakeBody::SnakeBody(const sf::Vector2i& position, std::vector<Entity*>* vec)
{
	this->type = Entity::snake_body;
	this->position = position;
	this->vec = vec;

	sprite.setSize(sf::Vector2f(BOX_SIZE - 2, BOX_SIZE - 2));
	sprite.setOrigin(sf::Vector2f((BOX_SIZE - 2) / 2, (BOX_SIZE - 2) / 2));
	sprite.setFillColor(sf::Color::White);
}

SnakeBody::SnakeBody(const SnakeBody& sb)
{
	this->position = sb.position;
	this->type = sb.type;
	this->sprite = sb.sprite;
	this->backPointer = sb.backPointer;
	this->vec = sb.vec;
}

void SnakeBody::updateBody(const sf::Vector2i& position, const bool& fruitEaten)
{
	sf::Vector2i actualPos = this->position;
	this->position = position;

	if (backPointer)
	{
		backPointer->updateBody(actualPos, fruitEaten);
		return;
	}
	
	if (fruitEaten)
	{
		backPointer = new SnakeBody(*this);
		backPointer->position = actualPos;
		vec->push_back(backPointer);
	}
}

SnakeBody::~SnakeBody()
{
}
