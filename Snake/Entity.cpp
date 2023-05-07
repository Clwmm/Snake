#include "Entity.h"

Entity::Entity(sf::Vector2i position, Type type)
{
    this->position = position;
    this->type = type;

    sprite.setSize(sf::Vector2f(BOX_SIZE, BOX_SIZE));
    //sprite.setRadius(BOX_SIZE / 2);
    //sprite.setPointCount(4);
    sprite.setOrigin(sf::Vector2f(BOX_SIZE/2, BOX_SIZE/2));
    //sprite.setRotation(45);
}

Entity::Entity()
{
}

Type Entity::getType()
{
    return this->type;
}

sf::Vector2i Entity::getPos()
{
    return this->position;
}

void Entity::update(float deltaTime, sf::RenderWindow& window)
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    
    sf::IntRect rext(sf::Vector2i(sprite.getPosition().x - (sprite.getSize().x/2), sprite.getPosition().y - (sprite.getSize().y / 2)), sf::Vector2i(sprite.getSize().x, sprite.getSize().y));
    if (rext.contains(sf::Vector2i(worldPos.x, worldPos.y)))
    {
        if (!contains)
        {
            contains = true;
            std::cout << "Mouse pos: " << "X: " << worldPos.x << " Y: " << worldPos.y << "\t";
            std::cout << "Box pos: X:" << sprite.getPosition().x << " Y: " << sprite.getPosition().y << std::endl;
        }
    }
    else
        contains = false;
}

void Entity::update(float deltaTime)
{
}

void Entity::draw(sf::RenderWindow& window)
{
    this->sprite.setPosition(this->position.x, this->position.y);
    window.draw(this->sprite);
}

Entity::~Entity()
{
}
