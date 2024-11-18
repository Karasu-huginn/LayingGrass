#include "main.h"

int main()
{

    int players_number;
    system("cls");
    while (true) {
        std::cout << "Please indicate how many players are participating : ";
        std::cin >> players_number;
        if (players_number >= 1 &&players_number <= 9) {
            break;
        } else {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    Game game(players_number);
    game.game_start();
    game.game_loop();
    return 0;
}


//  Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
