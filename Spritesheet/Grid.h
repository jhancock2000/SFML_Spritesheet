#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid {
public:
	Grid();
	~Grid() = default;

	Grid(int col, int row, Vector2f tileSize);

	
	//void export();
	
	void draw(RenderWindow& window);
	void setColor(Color color, RectangleShape* r);

	void Clear();

	std::vector<sf::RectangleShape*> rectangles;

private:
	const int GRID_SIZE = 32;

	Vector2f rectSize = { 32, 32 };
};
