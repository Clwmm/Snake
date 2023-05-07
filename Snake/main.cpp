#include "Map.h"
#include "SnakeHead.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Snake", sf::Style::Close);
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(LEVEL_SIZE * BOX_SIZE, LEVEL_SIZE * BOX_SIZE));
    window.setView(view);
    window.setFramerateLimit(60);

    sf::Clock clock;
    float deltaTime = 0;
       
    std::queue<Movement>* queue = new std::queue<Movement>;

    Map* map = Map::mapGenerator();

    SnakeBody* body = new SnakeBody(sf::Vector2i(-3*BOX_SIZE, 0), Type::snake_body, map->getVec());
    map->getVec()->push_back(body);
    SnakeHead* head = new SnakeHead(sf::Vector2i(-2*BOX_SIZE, 0), Type::snake_head, body, queue);
    map->getVec()->push_back(head);
    
    sf::Event event;
    while (window.isOpen())
    {
        // DELTA TIME
        deltaTime = clock.restart().asSeconds();

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

        // UPDATE
        head->update(deltaTime);


        // RENDER
        window.clear(sf::Color(18, 33, 43)); // Color background
        for (auto x : *map->getVec())
            x->draw(window);
        window.display();
    }

    delete map;

    return 0;
}