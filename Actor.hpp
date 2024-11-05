#pragma once
class Actor
{
public:
	int x, y; //Position on the map
	int ch; //ASCII code
	int color; //Color

	Actor(int x, int y, int ch, const int& color);
	void render() const;
};

