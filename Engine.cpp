#include "Engine.hpp"
#include "Actor.hpp"

Engine::Engine()
{
	player = new Actor(40, 25, '@', 15);
	actors.push_front(player);

}

Engine ::~Engine() {
	actors.clear();
	
}


void Engine::update()
{

}