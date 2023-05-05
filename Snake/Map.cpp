#include "Map.h"

Map::Map()
{
	vec = new std::vector<Entity*>;
}

Map* Map::mapGenerator()
{
	Map* tmp = new Map;

	for (int i = 0; i < LEVEL_SIZE - 1; i++)
	{
		Entity* tmp1 = new Entity(sf::Vector2i((-((LEVEL_SIZE - 1) / 2) * BOX_SIZE) + (BOX_SIZE * i), -((LEVEL_SIZE - 1) / 2) * BOX_SIZE), Type::wall);
		tmp1->sprite.setFillColor(sf::Color::Magenta);
		tmp->getVec()->push_back(tmp1);

		Entity* tmp2 = new Entity(sf::Vector2i((((LEVEL_SIZE - 1) / 2) * BOX_SIZE) - (BOX_SIZE * i), ((LEVEL_SIZE - 1) / 2) * BOX_SIZE), Type::wall);
		tmp2->sprite.setFillColor(sf::Color::Blue);
		tmp->getVec()->push_back(tmp2);

		Entity* tmp3 = new Entity(sf::Vector2i((((LEVEL_SIZE - 1) / 2) * BOX_SIZE), -((LEVEL_SIZE - 1) / 2) * BOX_SIZE + (BOX_SIZE * i)), Type::wall);
		tmp3->sprite.setFillColor(sf::Color::Green);
		tmp->getVec()->push_back(tmp3);

		Entity* tmp4 = new Entity(sf::Vector2i((-((LEVEL_SIZE - 1) / 2) * BOX_SIZE), ((LEVEL_SIZE - 1) / 2) * BOX_SIZE - (BOX_SIZE * i)), Type::wall);
		tmp4->sprite.setFillColor(sf::Color::Red);
		tmp->getVec()->push_back(tmp4);
	}

	return tmp;
}

std::vector<Entity*> *Map::getVec()
{
	return this->vec;
}

Map::~Map()
{
	for (Entity* x : *vec)
		delete x;
	vec->clear();
	delete vec;
}
