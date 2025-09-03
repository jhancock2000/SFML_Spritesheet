#include "Grid.h"
#include <sstream>

Grid::Grid() {

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++) {
            RectangleShape* rect = new RectangleShape();
            rect->setSize(rectSize);
            rect->setOutlineColor(Color::Red);
            //rect->setOutlineThickness(1);
            rect->setFillColor(Color::White);
            rect->setPosition({ float(600+j * rectSize.x), float(25+i * rectSize.y) });
            rectangles.push_back(rect);
        }

    }
}

Grid::Grid(int row, int col, Vector2f tileSize) {
    int offsetY = 0;
    for (int i = 0; i < row; i++)
    {
        offsetY += 10;
        int offset = 0;
        for (int j = 0; j < col; j++) {
            RectangleShape* rect = new RectangleShape();
            rect->setSize(tileSize);
            rect->setOutlineColor(Color::Red);
            //rect->setOutlineThickness(1);
            rect->setFillColor(Color::White);
            rect->setPosition({ float(  100 + offset + j * tileSize.x), float(400 + offsetY + i * tileSize.y) });
            rectangles.push_back(rect);
            offset += 10;
            //offsetY = 0;
        }
    }
}

void Grid::draw(RenderWindow& window) {
    for (auto rect : rectangles) {
        window.draw(*rect);
    }
}

void Grid::setColor(Color c, RectangleShape* r) {
    r->setFillColor(c);
}

void Grid::Clear() {
    for (auto a : rectangles) {
        a->setFillColor(Color::White);
    }
}

void Grid::exporttxt() {
    string fileText;
    std::ostringstream oss;
    for (size_t i = 0; i < rectangles.size(); i++) {
        sf::Color c = rectangles[i]->getFillColor();
        oss << "[" << (int)c.r << "," << (int)c.g << "," << (int)c.b << "][" << i << "]";
        if (i < rectangles.size() - 1)
            oss << ", ";
    }

    std::string output = oss.str();
    std::cout << output << std::endl;

    std::ofstream file("rectangles.txt");
    if (file.is_open()) {
        file << output;
        file.close();
    }
}

void Grid::loadtxt() {
    std::ifstream file("rectangles.txt");
    if (!file.is_open()) return;

    std::string data;
    std::getline(file, data);
    file.close();

    std::stringstream ss(data);
    char ch;
    int r, g, b, idx;

    while (ss >> ch) { // read '['
        if (ch != '[') continue;

        // Parse R,G,B
        ss >> r; ss >> ch; // ,
        ss >> g; ss >> ch; // ,
        ss >> b; ss >> ch; // ]

        // Skip to index
        ss >> ch; // should be '['
        ss >> idx;
        ss >> ch; // should be ']'

        // Apply color to rectangle at index
        if (idx >= 0 && idx < (int)rectangles.size()) {
            rectangles[idx]->setFillColor(sf::Color(r, g, b));
        }

        // Skip possible comma+space
        if (ss.peek() == ',') ss.ignore(2);
    }
}


