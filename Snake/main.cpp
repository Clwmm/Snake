#include "Map.h"
#include "SnakeHead.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Snake", sf::Style::Close);
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(LEVEL_SIZE * BOX_SIZE, LEVEL_SIZE * BOX_SIZE));
    window.setView(view);
       
    std::queue<Movement>* queue = new std::queue<Movement>;

    Map* map = Map::mapGenerator();
    map->getVec()->push_back(new SnakeHead(sf::Vector2i(0, 0), Type::snake_head, queue));
    
    sf::Event event;
    while (window.isOpen())
    {
        // WINDOW EVENTS
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Up:
                    queue->push(Movement::up);
                    break;
                case sf::Keyboard::Down:
                    queue->push(Movement::down);
                    break;
                case sf::Keyboard::Right:
                    queue->push(Movement::right);
                    break;
                case sf::Keyboard::Left:
                    queue->push(Movement::left);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        // MATH

        for (auto x : *map->getVec())
        {
            x->update(0, window);
        }

        if (queue->size() > 0)
        {
            switch (queue->front())
            {
            case Movement::up:
                std::cout << "UP" << std::endl;
                break;
            case Movement::down:
                std::cout << "DOWN" << std::endl;
                break;
            case Movement::right:
                std::cout << "RIGHT" << std::endl;
                break;
            case Movement::left:
                std::cout << "LEFT" << std::endl;
                break;
            default:
                break;
            }
            queue->pop();
        }

        
        

        // RENDER
        window.clear(sf::Color(18, 33, 43)); // Color background
        for (auto x : *map->getVec())
            x->draw(window);
        window.display();
    }

    delete map;

    return 0;
}