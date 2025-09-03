#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
using namespace std;

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Spritesheet Maker");
    window.setFramerateLimit(60);
     
    Grid grid;

    Grid grid2 = Grid(6, 8, {50, 50});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear({20,29,23});
        Vector2i mousePos = Mouse::getPosition(window);
        grid.draw(window);
        grid2.draw(window);
        for (auto a : grid.rectangles)
        {
            //printf("test");
            if (a->getGlobalBounds().contains({ float(mousePos.x), float(mousePos.y) })) {
                //grid.setColor({65, 65, 65}, a);
                RectangleShape r = *a;
                r.setFillColor({65, 65, 65});

                window.draw(r);
            }
        }

        window.display();
    }
}