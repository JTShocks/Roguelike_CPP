#pragma once
#include <stdio.h>
#include <list>

class Actor;
class Map;
class Engine
{
	std::list<Actor*> actors;
	Actor* player;
	Map* map;

	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine;
