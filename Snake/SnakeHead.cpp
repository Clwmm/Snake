#include "SnakeHead.h"

SnakeHead::SnakeHead(const sf::Vector2i& position, SnakeBody* backPointer, std::queue<Movement>* queue, std::vector<Entity*>* vec, bool* endPointer)
{
	this->type = Entity::snake_head;
	this->position = position;
    this->backPointer = backPointer;
	this->queue = queue;
    this->vec = vec;
    this->endPointer = endPointer;

	this->sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
	this->sprite.setOrigin(sf::Vector2f(BOX_SIZE / 2, BOX_SIZE / 2));
	this->sprite.setFillColor(sf::Color::White);

}

void SnakeHead::update(const float& deltaTime)
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

SnakeHead& SnakeHead::operator=(const Movement& m)
{
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
    sf::Vector2i oldPosition = position;
    *this = movement;

    switch (Functions::colision(this, vec))
    {
    case ColisionType::wall_c:
        *endPointer = true;
        return;

    case ColisionType::fruit_c:
        backPointer->updateBody(oldPosition, true);
        break;

    case ColisionType::none:
        backPointer->updateBody(oldPosition, false);
        break;

    default:
        break;
    }
}
