#include "Grid.h"

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


