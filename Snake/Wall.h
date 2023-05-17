#ifndef WALL_H
#define WALL_H

#include "Entity.h"

class Wall : virtual public Entity
{
public:
	Wall(const sf::Vector2i& position)
	{
		this->position = position;
		this->type = Entity::wall;

		sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
		sprite.setOrigin(sf::Vector2f(BOX_SIZE / 2, BOX_SIZE / 2));
		sprite.setFillColor(sf::Color::White);
	}

	// DEKLARACJA PRZYJACIELA
	friend class Map;
};

#endif // !WALL_H