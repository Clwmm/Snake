#ifndef ENTITY_H
#define ENTITY_H

#include "defines.h"

// TO JEST KLASA ABSTRAKCYJNA
class Entity
{
public:

	enum Type { wall, empty, snake_head, snake_body, fruit };
	enum ColisionType { wall_c, fruit_c, none };

	// WSZYTKIE METODY S¥ CZYSTO WIRTUALNE
	virtual Type getType()
	{
		return this->type;
	}

	virtual sf::Vector2i getPos()
	{
		return this->position;
	}

	virtual void update(const float& deltaTime) {}

	virtual void draw(sf::RenderWindow& window)
	{
		this->sprite.setPosition(this->position.x, this->position.y);
		window.draw(this->sprite);
	}

	virtual ~Entity() {}

	friend class Functions;

protected:
	sf::Vector2i position = { 0, 0 };
	Type type = Type::empty;
	sf::RectangleShape sprite;
};


class Functions
{
public:
	static int fromToRandom(const int& a, const int& b)
	{
		return (rand() % (b - a + 1)) + a;
	}

	static void moveFruit(Entity* entity, std::vector<Entity*>* vec)
	{
		int max_min = ((LEVEL_SIZE - 1) / 2) - 1;
		int rand_x = fromToRandom(-max_min, max_min) * BOX_SIZE;
		int rand_y = fromToRandom(-max_min, max_min) * BOX_SIZE;
		bool move = true;
		while (true)
		{
			for (auto x : *vec)
			{
				if (x->position.x == rand_x && x->position.y == rand_y)
					move = false;
			}
			if (move)
			{
				entity->position.x = rand_x;
				entity->position.y = rand_y;
				return;
			}
			rand_x = fromToRandom(-max_min, max_min) * BOX_SIZE;
			rand_y = fromToRandom(-max_min, max_min) * BOX_SIZE;
			move = true;
		}
	}

	static Entity::ColisionType colision(Entity* entity, std::vector<Entity*>* vec)
	{
		sf::Vector2i position = entity->position;
		// INERATORY
		// auto ptr przyjmuje vector<Entity*>::iterator
		for (auto ptr = vec->begin(); ptr < vec->end(); ++ptr)
		{
			if ((*ptr) != entity)
				if (position == (*ptr)->position)
				{
					switch ((*ptr)->type)
					{
					case Entity::wall:
						return Entity::wall_c;

					case Entity::fruit:
						moveFruit((*ptr), vec);
						return Entity::fruit_c;

					case Entity::snake_body:
						return Entity::wall_c;

					default:
						break;
					}
				}
		}
		return Entity::none;
	}
};


#endif // !ENTITY_H