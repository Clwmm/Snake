#pragma once

#include "Entity.h"

class Map
{
public:
	Map();
	static Map* mapGenerator();
	std::vector<Entity*>* getVec();
	~Map();

private:
	std::vector<Entity*>* vec = nullptr;
};

