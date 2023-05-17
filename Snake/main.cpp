#include "Map.h"
#include "SnakeHead.h"
#include "Fruit.h"
#include <conio.h>


/*
Komentarze:
    W SnakeBody.h:
        - klasy
        - konstruktory, destruktory
        - konstruktor kopiuj¹cy
        - dziedziczenie
    W SnakeHead.h:
        - przeciazenie operatora
    W Entity.h:
        - klasa abstrakcyjna
        - czysto wirtualne metody
        - iteratory
    W Wall.h:
        - deklaracja przyjaciela
    W Map.h:
        - szablon Vector<Entity*>
        - wyjatki
    W main.cpp:
        - zakresowa petla for
        - wyjatki
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Snake", sf::Style::Close);
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(LEVEL_SIZE * BOX_SIZE, LEVEL_SIZE * BOX_SIZE));
    window.setView(view);
    window.setFramerateLimit(60);
    srand(time(NULL));

    sf::Clock clock;
    float deltaTime = 0;
       
    std::queue<SnakeHead::Movement>* queue = new std::queue<SnakeHead::Movement>;

    Map* map = nullptr;

    // WYJATKI
    try
    {
        map = Map::mapGenerator();
    }
    catch (const int& err)
    {
        switch (err)
        {
        case -1:
            std::cout << "ERROR:\t";
            std::cout << "Declared LEVEL_SIZE is too small, value must be greater than 2" << std::endl;
            std::cout << "\n\tPress any key to exit";
            window.close();
            _getch();
            delete map;
            return -1;
        case -2:
            std::cout << "ERROR:\t";
            std::cout << "Declared BOX_SIZE is too small, value must be greater than 2" << std::endl;
            std::cout << "\n\tPress any key to exit";
            window.close();
            _getch();
            delete map;
            return -1;
        case -3:
            std::cout << "ERROR:\t";
            std::cout << "Declared LEVEL_SIZE is wrong, value must be odd number" << std::endl;
            std::cout << "\n\tPress any key to exit";
            window.close();
            _getch();
            delete map;
            return -1;
        case -4:
            std::cout << "ERROR:\t";
            std::cout << "Declared BOX_SIZE is wrong, value must be even number" << std::endl;
            std::cout << "\n\tPress any key to exit";
            window.close();
            _getch();
            delete map;
            return -1;

        default:
            break;
        }
    }
    bool* endPointer = new bool(false);

    SnakeBody* body = new SnakeBody(sf::Vector2i(-3*BOX_SIZE, 0), map->getVec());
    map->getVec()->push_back(body);
    SnakeHead* head = new SnakeHead(sf::Vector2i(-2*BOX_SIZE, 0), body, queue, map->getVec(), endPointer);
    map->getVec()->push_back(head);

    Fruit* fruit = new Fruit(sf::Vector2i(3 * BOX_SIZE, 0));
    map->getVec()->push_back(fruit);
    
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
                    queue->push(SnakeHead::Movement::up);
                    break;
                case sf::Keyboard::Down:
                    queue->push(SnakeHead::Movement::down);
                    break;
                case sf::Keyboard::Right:
                    queue->push(SnakeHead::Movement::right);
                    break;
                case sf::Keyboard::Left:
                    queue->push(SnakeHead::Movement::left);
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

        if (*endPointer)
        {
            window.close();
            break;
        }

        // RENDER
        window.clear(sf::Color(18, 33, 43)); // Color background
        
        // ZAKRESOWA PETLA FOR
        for (auto x : *map->getVec())
            x->draw(window);
        window.display();
    }

    delete map;
    delete endPointer;

    return 0;
}