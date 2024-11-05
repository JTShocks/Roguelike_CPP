#pragma once

struct Tile {
	bool canWalk; //Can actors walk on this tile
	Tile() : canWalk(true) {}
};
class Map
{
public:
	int width, height;
	Map(int width, int height);
	~Map();
	bool isWall(int x, int y) const;
	void render() const;
protected:
	Tile* tiles;
	void SetWall(int x, int y);
};

