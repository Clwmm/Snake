#include "SnakeBody.h"

SnakeBody::SnakeBody(const sf::Vector2i& position, const Type& type, std::vector<Entity*>* vec)
{
	this->type = type;
	this->position = position;
	this->vec = vec;

	sprite.setSize(sf::Vector2f(BOX_SIZE - 2, BOX_SIZE - 2));
	sprite.setOrigin(sf::Vector2f((BOX_SIZE - 2) / 2, (BOX_SIZE - 2) / 2));
	sprite.setFillColor(sf::Color::White);
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
		backPointer = new SnakeBody(actualPos, Type::snake_body, vec);
		vec->push_back(backPointer);
	}
}

SnakeBody::~SnakeBody()
{
}
