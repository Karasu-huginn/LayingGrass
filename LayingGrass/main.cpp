#include "main.h"

int main()
{

    int players_number;
    std::cout << "Please indicate how many players are participating : " << std::endl;
    std::cin >> players_number;
    Game game(players_number);
    game.game_start();
    return 0;
}

//  Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
