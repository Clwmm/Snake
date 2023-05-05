#include "SnakeBody.h"

SnakeBody::SnakeBody(sf::Vector2i position, Type type, std::vector<Entity*>* tmpvec)
{
	this->type = type;
	this->position = position;
	this->tmpvec = tmpvec;

	sprite.setSize(sf::Vector2f(BOX_SIZE - 2, BOX_SIZE - 2));
	sprite.setOrigin(sf::Vector2f((BOX_SIZE - 2) / 2, (BOX_SIZE - 2) / 2));
	sprite.setFillColor(sf::Color::White);
}

void SnakeBody::updateBody(sf::Vector2i position, bool fruitEaten)
{
	sf::Vector2i actualPos = this->position;
	this->position = position;
	
	if (backPointer)
	{
		backPointer->updateBody(actualPos, fruitEaten);
		return;
	}

	backPointer = new SnakeBody(actualPos, Type::snake_body, tmpvec);
	tmpvec->push_back(backPointer);
}

SnakeBody::~SnakeBody()
{
}
