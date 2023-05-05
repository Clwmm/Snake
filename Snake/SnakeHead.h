#pragma once
#include "SnakeBody.h"

enum class Movement {up = 1, down = -1, right = 2, left = -2};
/*
include queue
std::queue

add to queue all arrow signals from keyboard

in every iteration of movement pop from queue signal

create queue in game class and cast pointer to constructor of SnakeHead
*/


class SnakeHead : public Entity
{
public:
	SnakeHead(sf::Vector2i, Type, std::queue<Movement>*);
	void update(float deltaTime);
	~SnakeHead();
private:
	SnakeBody* backPointer = nullptr;
	std::queue<Movement>* queue = nullptr;
};

