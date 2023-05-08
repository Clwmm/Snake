#pragma once
#include "Entity.h"
class SnakeBody : public Entity 
{
public:
	SnakeBody(const sf::Vector2i&, const Type&, std::vector<Entity*>*);
	void updateBody(const sf::Vector2i&, const bool&);
	~SnakeBody();
private:
	SnakeBody* backPointer = nullptr;
	std::vector<Entity*>* vec = nullptr;
};

