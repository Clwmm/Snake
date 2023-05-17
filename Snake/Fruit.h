#ifndef FRUIT_H
#define FRUIT_h

#include "Entity.h"

class Fruit : public Entity
{
public:
	Fruit(const sf::Vector2i& position)
	{
		this->position = position;
		this->type = Entity::fruit;

		sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
		sprite.setOrigin(sf::Vector2f(BOX_SIZE / 2, BOX_SIZE / 2));
		sprite.setFillColor(sf::Color::Yellow);
	}

};

#endif // !FRUIT_H