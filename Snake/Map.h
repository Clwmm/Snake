#ifndef MAP_H
#define MAP_H

#include "Wall.h"

class Map
{
public:
	Map()
	{
		vec = new std::vector<Entity*>;
	}

	std::vector<Entity*>* getVec()
	{
		return this->vec;
	}

	static Map* mapGenerator()
	{
		Map* tmp = new Map;

		// WYRZUCANIE WYJ¥TKU
		if (LEVEL_SIZE < 3)
			throw - 1;
		if (BOX_SIZE < 3)
			throw - 2;
		if (LEVEL_SIZE % 2 != 1)
			throw - 3;
		if (BOX_SIZE % 2 != 0)
			throw - 4;

		for (int i = 0; i < LEVEL_SIZE - 1; i++)
		{
			Wall* tmp1 = new Wall(sf::Vector2i((-((LEVEL_SIZE - 1) / 2) * BOX_SIZE) + (BOX_SIZE * i), -((LEVEL_SIZE - 1) / 2) * BOX_SIZE));
			tmp1->sprite.setFillColor(sf::Color::Magenta);
			tmp->getVec()->push_back(tmp1);

			Wall* tmp2 = new Wall(sf::Vector2i((((LEVEL_SIZE - 1) / 2) * BOX_SIZE) - (BOX_SIZE * i), ((LEVEL_SIZE - 1) / 2) * BOX_SIZE));
			tmp2->sprite.setFillColor(sf::Color::Blue);
			tmp->getVec()->push_back(tmp2);

			Wall* tmp3 = new Wall(sf::Vector2i((((LEVEL_SIZE - 1) / 2) * BOX_SIZE), -((LEVEL_SIZE - 1) / 2) * BOX_SIZE + (BOX_SIZE * i)));
			tmp3->sprite.setFillColor(sf::Color::Green);
			tmp->getVec()->push_back(tmp3);

			Wall* tmp4 = new Wall(sf::Vector2i((-((LEVEL_SIZE - 1) / 2) * BOX_SIZE), ((LEVEL_SIZE - 1) / 2) * BOX_SIZE - (BOX_SIZE * i)));
			tmp4->sprite.setFillColor(sf::Color::Red);
			tmp->getVec()->push_back(tmp4);
		}

		return tmp;
	}

	~Map()
	{
		for (Entity* x : *vec)
			delete x;
		vec->clear();
		delete vec;
	}

private:
	// SZABLON VECTOR
	std::vector<Entity*>* vec = nullptr;
};

#endif // !MAP_H