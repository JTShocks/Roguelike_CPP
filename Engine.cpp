#include "Engine.hpp"
#include "Actor.hpp"
#include <conio.h>
#include <Windows.h>
/*Engine::Engine()
{
	player = new Actor(40, 25, '@', 15);
	actors.push_front(player);
	//map = new Map(80, 45);

}

Engine ::~Engine() {
	actors.clear();
	delete map;
}


void Engine::update()
{
	char keyPressed = _getch();


	if (GetKeyState(keyPressed) & 0x8000)
	{
		//Check if the Key is pressed and if the high-order bit is set
		switch (keyPressed)
		{
			case 'A':
				//Move to the Left
				if (!map->isWall(player->x - 1, player->y))
				{
					player->x--;
				}
			break;
			case 'D':
				if (!map->isWall(player->x + 1, player->y))
				{
					player->x++;
				}
				//Move to the Right
				break;
			case 'W':
				if (!map->isWall(player->x, player->y-1))
				{
					player->y--;
				}
				//Move up
				break;
			case 'S':
				if (!map->isWall(player->x, player->y+1))
				{
					player->y++;
				}
				//Move down
				break;
			default:break;
		}
	}
}

void Engine::render() {
	
	map->render();
	//Draw all actors
	for (Actor** iterator = actors.begin(); iterator != actors.end(); iterator++)
	{
		(*iterator)->render();
	}
}*/