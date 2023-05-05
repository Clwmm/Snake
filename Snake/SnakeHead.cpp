#include "SnakeHead.h"

SnakeHead::SnakeHead(sf::Vector2i position, Type type, std::queue<Movement>* queue)
{
	this->type = type;
	this->position = position;
	this->queue = queue;

	this->sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
	this->sprite.setOrigin(sf::Vector2f(BOX_SIZE / 2, BOX_SIZE / 2));
	this->sprite.setFillColor(sf::Color::Red);

}

void SnakeHead::update(float deltaTime)
{
    
}

SnakeHead::~SnakeHead()
{
}
