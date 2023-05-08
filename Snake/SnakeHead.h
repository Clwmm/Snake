#pragma once
#include "SnakeBody.h"

enum class Movement {up = 1, down = -1, right = 2, left = -2, none = 0};
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
	SnakeHead(const sf::Vector2i&, const Type&, SnakeBody*, std::queue<Movement>*, std::vector<Entity*>*, bool*);
	void update(const float& deltaTime);
	~SnakeHead();

	SnakeHead& operator=(const Movement& m);
private:
	SnakeBody* backPointer = nullptr;
	std::queue<Movement>* queue = nullptr;
	std::vector<Entity*>* vec = nullptr;
	void move();

	Movement movement = Movement::none;
	float time = 0;
	bool startMovement = false;
	bool* endPointer = nullptr;
};

