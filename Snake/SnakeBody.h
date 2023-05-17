#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Entity.h"

// DEKLARACJA KLASY, z DZIEDZICZENIEM OD CLASY ENTITY
class SnakeBody : virtual public Entity
{
public:
	// DEKLARACJA KONSTRUKTORA
	SnakeBody(const sf::Vector2i&, std::vector<Entity*>*);
	// DEKLARACJA KONSTRUKTORA KOPIUJACEGO
	SnakeBody(const SnakeBody& sb);
	void updateBody(const sf::Vector2i&, const bool&);
	// DEKLARACJA DESTRUKTORA
	~SnakeBody();
private:
	SnakeBody* backPointer = nullptr;
	std::vector<Entity*>* vec = nullptr;
};

#endif // !SNAKEBODY_H