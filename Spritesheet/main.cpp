#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
#include <random>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

using namespace sf;
int main()
{
    bool click = false;
    bool click2 = false;
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Spritesheet Maker");
    window.setFramerateLimit(60);
    
    Color currentColour = Color::Black;
    Color secondColour = Color::White;
    Grid grid;

    Grid grid2 = Grid(6, 8, {50, 50});

    //vector<Grid*> grids;

    RectangleShape clear;
    clear.setPosition({ 0,0 });
    clear.setSize({ 250, 100 });


    for (auto a : grid2.rectangles) {
        a->setFillColor({ uint8_t(floor(rand() % 255)), uint8_t(floor(rand() % 255)), uint8_t(floor(rand() % 255)) });
    }


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
            click2 = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

            if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
                grid.exporttxt();
            }

            if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
                grid.loadtxt();
            }


            
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear({20,29,23});
        Vector2i mousePos = Mouse::getPosition(window);
        grid.draw(window);
        grid2.draw(window);

        if (clear.getGlobalBounds().contains({ float(mousePos.x), float(mousePos.y) }) && click) {
            grid.Clear();

        }

        for (auto a : grid.rectangles)
        {
            //printf("test");
            if (a->getGlobalBounds().contains({ float(mousePos.x), float(mousePos.y) })) {
                //grid.setColor({65, 65, 65}, a);
                RectangleShape r = *a;
                r.setFillColor({65, 65, 65, 100});  


                if (click) {
                    a->setFillColor(currentColour);
                    click = false;
                }
                if (click2) {
                    a->setFillColor(secondColour);
                    click2 = false;
                }
                window.draw(r);
            }
        }

        for (auto a : grid2.rectangles) {
            if (a->getGlobalBounds().contains({ float(mousePos.x), float(mousePos.y) })) {
                RectangleShape r = *a;
                r.setOutlineColor(Color::White);
                r.setOutlineThickness(2);
                window.draw(r);
                if (click) {
                    currentColour = r.getFillColor();
                    click = false;
                }
            }
        }

        window.draw(clear);

        window.display();
    }
}


/*
* TODOS:
* Fix onClick bug. as long as mouse is down, onclick is always on
* replace white background with transparent texture
* export rectangle vector with formatting [RGB][POS]
* IMPORT a vector
* export as PNG??????
* Refactor everything into classes.....hard
* Have set colours, not random everytime
* Fix that skipping bug for drawing
* Add different pen styles/sizes?
* Put clear button somewhere that makes sense
*
* 
*/