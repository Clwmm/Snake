#pragma once
#include "defines.h"

enum class Type{wall, empty, snake_head, snake_body, fruit};
enum class ColisionType { wall, fruit, none };

class Entity
{
public:
	Entity(sf::Vector2i position, Type type);
	Entity();
	virtual Type getType();
	virtual sf::Vector2i getPos();
	virtual void update(float deltaTime, sf::RenderWindow& window);
	virtual void update(const float& deltaTime);
	virtual void draw(sf::RenderWindow& window);
	virtual ~Entity();

	static ColisionType colision(Entity* entity, std::vector<Entity*>* vec);

protected:
	sf::Vector2i position = { 0, 0 };
	Type type = Type::empty;
	sf::RectangleShape sprite;

	bool contains = false;

	friend class Map;
};

