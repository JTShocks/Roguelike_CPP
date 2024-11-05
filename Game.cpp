#include <iostream>
#include <regex>
#include <random> //Allows the random fuction
#include <algorithm>
#include <memory> //Namespace to allow the manipulation of memory
#include <cctype>
#include <deque>
#include <map> //Is a way to map data/ is a Dictionary
#include <set>
#include <print>
#include "Actor.hpp"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

static std::mt19937 rnd;

/*frand() generates a random number between 0 and 1*/
#define frand() std::uniform_real_distribution<>(0.1f, 1.f)(rnd)
/*Generate a random number of a specified range*/
#define rand(size) std::uniform_int_distribution<>(0, (size)-1)(rnd)
/*Return the size of an array at compile time*/
template<typename T, std::size_t size>
constexpr std::size_t count(const T(&)[size])
{
    return size;
}

//This is a syntactic shorthand for regular expressions
static std::regex operator ""_r(const char* pattern, std::size_t length)
{
    return std::regex(pattern, length);
}



struct GenericData
{
    //Structure based on the Pathfinder2e system for bulk and similar weight
    //Information that all things in the game have
    const char* name;
    float worth;
    float weight; //L = 0.1. Negligible = 0.01
} static const
//Determining the different types of coins
MoneyTypes[] =
{ {"gold", 1, 0.01}, {"silver", 0.1, 0.01}, {"copper", 0.01, 0.01} },

//List different kinds of "terrain" for the variance.
EnvTypes[] =
{ {"arctic", 0,0},{"aquatic", 0,0}, {"forest", 0,0}, {"underground", 0,0} };

struct Room
{
    std::size_t Wall = 0, Env = 0; //These are indexes for the kind of environment the room is
    unsigned seed = 0; //Seed for the dungeon generation

} static const defaultroom;
struct Dungeon
{
    /*A dungeon contains rooms*/
    std::map<long/*x*/, std::map<long/*y*/, Room>> rooms;

    //Generate a room at the given coordinates
    //The model room will help the dungeon create similar rooms, rather than completely random rooms of the different types
    Room& GenerateRoom(long x, long y, const Room& model, unsigned seed)
    {
        rnd.seed(y * 0xc70f7907UL + x * 216613621UL);
        auto insres = rooms[x].insert({ y, model });
        Room& room = insres.first->second;
        if (insres.second)
        {
            //If a new room was inserted, make changes
            room.seed = (seed + (frand() > 0.95 ? rand(4) : 0)) & 3;
            //10% chance for the room environment type to change.
            if (frand() > 0.9)
            {
                room.Env = rand(count(EnvTypes));
            }
            if (frand() > (seed == model.seed ? 0.95 : 0.1))
                room.Wall = frand() < 0.4 ? 2 : 0;
        }
            return room;
    }
    char Char(long x, long y) const
    {
        //This is what determines the display of a given room
        auto i = rooms.find(x); 
        if (i == rooms.end())    return ' '; //Blank space, reached the end of the row
        auto j = i->second.find(y);
        if (j == i->second.end()) return ' '; //Blank space, reached the end of the column
        if (j->second.Wall)    return '#'; //# to represent a solid wall
        return '.'; // a . to represent solid ground
    }
} static dungeon;

//Keeping track of the Player's location and life
static long x = 0, y = 0, life = 100;
Actor* player;

bool isRunning;
static bool CanMoveTo(long wherex, long wherey, const Room& model = defaultroom)
{
    if (!dungeon.GenerateRoom(wherex, wherey, model, 0).Wall) return true;
    return false;
}
static Room& SpawnRooms(long wherex, long wherey, const Room& model = defaultroom)
{
    Room& room = dungeon.GenerateRoom(wherex, wherey, model, 0);
#define Spawn4rooms(x,y)
    for (char p : {1, 3, 5, 7}) \
        dungeon.GenerateRoom(x + p % 3 - 1, y + p % 3 - 1, room, (p + 1) / 2)
    Spawn4rooms(wherex, wherey);
    for (int o = 1; o < 5 && CanMoveTo(wherex, wherey + o, room); o++) Spawn4rooms(wherex, wherey + o);
    for (int o = 1; o < 5 && CanMoveTo(wherex, wherey - o, room); o++) Spawn4rooms(wherex, wherey - o);
    for (int o = 1; o < 6 && CanMoveTo(wherex-o, wherey, room); o++) Spawn4rooms(wherex-o, wherey);
    for (int o = 1; o < 6 && CanMoveTo(wherex+o, wherey, room); o++) Spawn4rooms(wherex+o, wherey);
    return room;
}

//Routine provides view for the player and generates new dungeon data
static void Look()
{
    const Room& room = SpawnRooms(x, y);

    std::vector<std::string> mapgraph;
    for (long yo = -4; yo <= 4; yo++)
    {
        std::string line;
        for (long xo = -5; xo <= 5; xo++)
        {
            char c = ((xo == 0 && yo == 0) ? '@' : dungeon.Char(player->x + xo, player->y + yo));
            line += c;
        }
        //Rendering the line of characters and storing them
        //Once made, push to the back of the list
        mapgraph.push_back(line);

    }
}
static bool TryMoveBy(int xd, int yd)
{

}
int main()
{
    std::cout << "Hello World!\n";
    player = new Actor(0, 0, '@', 15);
    isRunning = true;
    Look();
    //The main loop
    while (isRunning)
    {


        //if (GetKeyState('A') & 0x8000)
        if (_kbhit())
        {
            char keyPressed = _getch();
            //Check if the Key is pressed and if the high-order bit is set
            switch (keyPressed)
            {
            case 'a':
                //Move to the Left
                std::cout << "Moving left" << std::endl;
                break;
            case 'd':
                //Move to the Right
                break;
            case 'w':
                //Move up
                break;
            case 's':
                //Move down
                break;
            default:break;
            }
        }
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
