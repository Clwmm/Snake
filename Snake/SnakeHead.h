#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "SnakeBody.h"


class SnakeHead : virtual public Entity
{
public:
	enum Movement { up = 1, down = -1, right = 2, left = -2, none = 0 };

	SnakeHead(const sf::Vector2i&, SnakeBody*, std::queue<Movement>*, std::vector<Entity*>*, bool*);
	void update(const float& deltaTime);
	~SnakeHead() {}

	// PRZECIAZENIE OPERATORA =
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

#endif // !SNAKEHEAD_H