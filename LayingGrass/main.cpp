#include "main.h"


int main()
{
    int players_number;
    std::cout << "Please indicate how many players are participating : " << std::endl;


    Color yellow("yellow");
    std::cout << yellow.colorize_text("this is a test") << std::endl;


    return 0;
    //std::cin >> players_number;
    //Game game(players_number);
}

//  Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
