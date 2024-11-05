#include "Actor.hpp"
#include "Windows.h"


Actor :: Actor(int x, int y, int ch, const int &color) :
	x(x), y(y), ch(ch), color(color){}

void Actor::render() const {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
