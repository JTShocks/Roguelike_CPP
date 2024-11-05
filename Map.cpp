#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
	tiles = new Tile[width * height];

}

Map::~Map() {
	delete[] tiles; //Removes all the tiles
}

/*Helper to determine if a given location is a wall before moving player to it*/
bool Map::isWall(int x, int y) const {
	return !tiles[x + y * width].canWalk;
}
/*Sets the walls of a given location*/
void Map::SetWall(int x, int y) {
	tiles[x + y * width].canWalk = false;
}

void Map::render() const {
	//Add in references to the color of the walls

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			//std::cout
		}
	}
}