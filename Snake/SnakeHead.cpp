#include "SnakeHead.h"

SnakeHead::SnakeHead(sf::Vector2i position, Type type, SnakeBody* backPointer, std::queue<Movement>* queue)
{
	this->type = type;
	this->position = position;
    this->backPointer = backPointer;
	this->queue = queue;

	this->sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
	this->sprite.setOrigin(sf::Vector2f(BOX_SIZE / 2, BOX_SIZE / 2));
	this->sprite.setFillColor(sf::Color::White);

}

void SnakeHead::update(float deltaTime)
{
    if (time < MOVEMENT_TIME)
    {
        time += deltaTime;
        return;
    }
    time = 0;

    if (queue->size() > 0)
    {
        while (queue->size() >= 4)
            queue->pop();
        switch (queue->front())
        {
        case Movement::up:
            if (movement != Movement::down)
                movement = Movement::up;
            break;
        case Movement::down:
            if (movement != Movement::up)
                movement = Movement::down;
            break;
        case Movement::right:
            if (movement != Movement::left)
                movement = Movement::right;
            break;
        case Movement::left:
            if (movement != Movement::right)
                movement = Movement::left;
            break;
        default:
            break;
        }
        queue->pop();
    }


    if (startMovement)
        move();
    else
    {
        if (movement != Movement::none)
        {
            startMovement = true;
            move();
        }
    }
}

SnakeHead::~SnakeHead()
{
}

SnakeHead& SnakeHead::operator=(const Movement& m)
{
    // TODO: insert return statement here
    switch (m)
    {
    case Movement::up:
        this->position.y -= BOX_SIZE;
        break;

    case Movement::down:
        this->position.y += BOX_SIZE;
        break;

    case Movement::right:
        this->position.x += BOX_SIZE;
        break;

    case Movement::left:
        this->position.x -= BOX_SIZE;
        break;
    default:
        break;
    }
    return *this;
}

void SnakeHead::move()
{
    backPointer->updateBody(this->getPos(), false);
    *this = movement;
}
