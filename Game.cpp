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

bool isRunning;
int main()
{
    std::cout << "Hello World!\n";

    //The main loop
    while (isRunning)
    {

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
