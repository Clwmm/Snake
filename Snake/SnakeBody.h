#pragma once
#include "Entity.h"
class SnakeBody : public Entity 
{
public:
	SnakeBody(sf::Vector2i position, Type type, std::vector<Entity*>* tmpvec);
	void updateBody(sf::Vector2i, bool);
	~SnakeBody();
private:
	SnakeBody* backPointer = nullptr;
	std::vector<Entity*>* tmpvec = nullptr;
};

