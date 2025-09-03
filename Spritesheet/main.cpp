#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Spritesheet Maker");
    window.setFramerateLimit(60);
     
    const int GRID_SIZE = 32;

    sf::Color currentcolour = sf::Color(Color::White);

    vector<RectangleShape*> rectangles;

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++) {
            RectangleShape* rect = new RectangleShape();
            rect->setSize({ 32,32 });
            rect->setOutlineColor(Color::Red);
            //rect->setOutlineThickness(1);
            rect->setFillColor(Color::White);
            rect->setPosition({ float(400 + j * GRID_SIZE), float(25 + i * 32)});
            rectangles.push_back(rect);
        }

    }



    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear({20,29,23});
        Vector2i mousePos = Mouse::getPosition(window);
        for (auto a : rectangles)
        {
            //printf("test");
            if (a->getGlobalBounds().contains({ float(mousePos.x+1), float(mousePos.y+1) })) {
                a->setFillColor({65, 65, 65});


            }
            else {
                a->setFillColor(currentcolour);
            }
            window.draw(*a);
        }
        window.display();
    }
}