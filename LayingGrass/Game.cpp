#include "Game.h"

Game::Game(int pn) {
	std::cout << "Initializing Game..." << std::endl;
	players_number = pn;
	tiles_number = ceil(pn * 10.67);
	init_players();
	init_tiles_queue();
	board = Board(pn);
	player_turn = pn * 9;
}

Game::~Game() {

}

void Game::init_players() {
	std::cout << "Initializing Players..." << std::endl;
	std::string name;
	for (int i = 0; i < players_number; i++) {
		std::cout << "Enter the name of the player " << i << " : " << std::endl;
		std::cin >> name;
		players.push_back(Player(name, char(i)));
	}
	std::cout << "Players initialized !" << std::endl;
}

void Game::init_tiles_queue() {
	std::cout << "Initializing Tiles queue..." << std::endl;
	std::ifstream file("Tileslist.json");
	nlohmann::json data = nlohmann::json::parse(file);
	std::cout << "Randomazing queue..." << std::endl;
	tiles_queue_randomize(data);
	std::cout << "Tiles queue initialized !" << std::endl;
}

void Game::tiles_queue_randomize(nlohmann::json data) {
	int random_tile_indexes[96];
	int ite;
	generate_rand_ind(random_tile_indexes);
	for (int i = 0; i < tiles_number; i++) {
		ite = random_tile_indexes[i];
		tiles_queue.push(Tile(data[ite]));
	}
}

void Game::generate_rand_ind(int(&rand_tile_ind)[96]) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 95);

	int number;
	for (int i = 0; i < 96; i++) {
		do {
			number = dist(mt);
		} while (queue_has_number(number, rand_tile_ind));
		rand_tile_ind[i] = number;
	}
}

bool Game::queue_has_number(int number, int rand_tile_ind[96]) {
	for (int i = 0; i < 96; i++) {
		if (number == rand_tile_ind[i]) {
			return true;
		}
	}
	return false;
}


void Game::display_current_next_tiles_queued(std::queue<Tile> tiles_queue) {
    for (int i = 0; i < 6 ; i++) {
		if (i == 0) {
			std::cout << "Current tile : " << std::endl;
            tiles_queue.front().display();
			std::cout << "\n Next tiles :" << std::endl;
		} else {
			std::cout << "Tile " << i << " : " << std::endl; 
			tiles_queue.front().display();
		}
        tiles_queue.pop();
    }
}

int Game::display_turn_actions(int exchange_number) {
    int converted_choice;

    std::cout << "1- Exchange tile (total : " << exchange_number << ")" << std::endl;
    std::cout << "2- Place tile" << std::endl;
    std::cout << "3- Rotate tile" << std::endl;
    std::cout << "4- Flip tile (horizontally)" << std::endl;
    std::cout << "5- Flip tile (vertically)" << std::endl;
    std::cout << "6- End turn" << std::endl << std::endl;
	converted_choice = input_int(1, 6, "Choose your action (1, 2, 3, 4, 5, 6): ");
    return converted_choice;
}

void Game::clear_cin() {
	std::cin.clear();
	std::cin.sync();
}

int Game::input_int(int min, int max, std::string text) {
    std::string input;
    int converted_input;

	while (true) {
		clear_cin();
        std::cout << text;
        std::getline(std::cin, input);

        if (input.length() == 1 and std::isdigit(input[0])) {
            converted_input = std::stoi(input);
            if (converted_input >= min and converted_input <= max) {
                break; 
            }
        }
        std::cout << "Invalid input!" << std::endl;
    }
    return converted_input;
}

void Game::input_string(char &user_pos, std::string text) {
	std::string input;

	while (true) {
		clear_cin();
		std::cout << text;
        std::getline(std::cin, input);
		if (input.length() == 1 and std::isalpha(input[0]) and input[0] != ' ') {
            user_pos = input[0];
            break;
        } else {
			std::cout << "Invalid input!" << std::endl;
		}
	}
}

void Game::clear_terminal() {
	system("cls");
}

void Game::game_start() {
	char player_character;
	
	for (int i = 0; i < players_number; i++) {
		clear_terminal();
		std::cout << std::endl << "Player " << players[i].get_name() << "'s turn :" << std::endl;
		player_character = players[i].get_char();
		board.display_board();
		place_base(player_character);
	}
}

void Game::display_ending_turn() {
	std::cout << "ending turn..." << std::endl;
	Sleep(1000);
}

void Game::check_bonus_playability(Player &player) {
	if (player.get_rob_number() > 0) {
		rob_tile(player.get_char());
	}
	if (player.get_stone_number() > 0) {
		std::cout << "Current tile : " << std::endl;
		tiles_queue.front().display();
		place_stone();
	}
	
}

void Game::game_loop() {
    int action_choice;
	bool end_turn;
	int winning_player_index = 0;
	int winning_player_score = 0;

    while (player_turn > 0) { 
        for (int i = 0; i < players_number; i++) {
            if (player_turn == 0) {
                break;
            }
			while (true) {
				clear_terminal();
				board.display_board();
				std::cout << std::endl;
				display_current_next_tiles_queued(tiles_queue);
				std::cout << "turns left : " << player_turn << std::endl;
            	std::cout << "Player " << players[i].get_name() << "'s turn :" << std::endl << std::endl;
            	action_choice = display_turn_actions(players[i].get_exchange_number()); 
				if (action_choice == 6) {
                    break;
                }
				if (action_choice == 1) {
					if (players[i].get_exchange_number() <= 0) {
						std::cout << "You don't have any exchange coupons !" << std::endl;
                        continue;
					} else {
						players[i].decrement_exchange_number();
					}
				}
				end_turn = make_action(action_choice);
				if (end_turn) {
                    break;
                }
			}
			display_ending_turn();
			board.get_bonus(players[i]);
			check_bonus_playability(players[i]);
            player_turn--;
        }
    }
	game_last_actions(players);
	board.check_victory(winning_player_score, winning_player_index);
	clear_terminal();
	board.display_board();
	std::cout << "player :" << players[winning_player_index].get_name() << "won the game !!!" << std::endl;
    std::cout << "GG WP" << std::endl;
}


void Game::game_last_actions(std::vector<Player> &players) {
	for (int i = 0; i < players_number; i++) {
		clear_terminal();
		std::cout << "Game Ended" << std::endl;
		std::cout << "Last Actions !" << std::endl << std::endl;
		board.display_board();
		std::cout << "Player " << players[i].get_name() << "'s turn :" << std::endl;
		std::cout << "Player " << players[i].get_name() << " has " << players[i].get_exchange_number() << " exchange coupons" << std::endl;
		if (players[i].get_exchange_number() <= 0) {
			std::cout << "Player " << players[i].get_name() << " has no more exchange coupons !" << std::endl;
			display_ending_turn();
			continue;
		} else {
			while (players[i].get_exchange_number() > 0) {
				std::cout << "Player " << players[i].get_name() << " can buy : " << players[i].get_exchange_number()<< " grass tile(s)" <<std::endl;
                buy_grass_tile(players[i].get_char());
				players[i].decrement_exchange_number();
			}
			std::cout << "Player " << players[i].get_name() << " has no more exchange coupons to buy grass tile(s) !" << std::endl;
            display_ending_turn();
            continue;
		}
	}
}

bool Game::make_action(int action) {
	if (action == 1) {
		std::cout << "exchange tile" << std::endl;
		exchange_tile();
		return false;		
	} else if (action == 2) {
		std::cout << "place tile" << std::endl;
		place_tile('a');
		return true;
	} else if (action == 3) {
		std::cout << "rotate tile" << std::endl;
		tiles_queue.front().rotate();
		return false;
	} else if (action == 4) {
		std::cout << "flip tile horizontally" << std::endl;
		tiles_queue.front().flip_h();
		return false;
	} else if (action == 5) {
		std::cout << "flip tile vertically" << std::endl;
		tiles_queue.front().flip_v();
		return false;
	}
	return false;
}

void Game::exchange_tile() {
	int choice;

	display_current_next_tiles_queued(tiles_queue);
	choice = input_int(1, 5, "Choose the tile you want to exchange with (1-5): ");
	for (choice = choice; choice != 0; choice--) {
		Tile temp_tile = tiles_queue.front();
		tiles_queue.pop();
		tiles_queue.push(temp_tile);
	}
}





void Game::interpret_coords(char &x, char &y) {
	if (x > 'Z') {
		x -= 'G';
	}
	else {
		x -= 'A';
	}
	if (y > 'Z') {
		y -= 'G';
	}
	else {
		y -= 'A';
	}
}

void Game::ask_coords(char &user_x, char &user_y, std::string text) {
	std::cout << std::endl << "Please enter the coordinates of the square you'd like to " << text << " on x (columns) and y (lines)" << std::endl;
	input_string(user_y, "x : ");
	input_string(user_x, "y : ");
	interpret_coords(user_x, user_y);
}



void Game::place_stone() {
	char user_x;
	char user_y;
	do {
		ask_coords(user_x, user_y, "place your stone");
	} while (!board.place_stone(tiles_queue.front(), int(user_x), int(user_y)));
	Tile temp_tile = tiles_queue.front();
	tiles_queue.pop();
	tiles_queue.push(temp_tile);
}

void Game::rob_tile(char player) {
	char user_x;
	char user_y;
	do {
		ask_coords(user_x, user_y, "rob");
	} while (board.rob_tile(int(user_x), int(user_y), player));
}

void Game::buy_grass_tile(char player) {
	char user_x;
	char user_y;
	do {
		ask_coords(user_x, user_y, "place your grass tile");
	} while (!board.buy_grass_tile(int(user_x), int(user_y), player));
}

void Game::bases_placement() {
	for (int i = 0; i < players_number; i++) {
		place_base(players[i].get_char());
	}
}

void Game::place_base(char player) {
	char user_x;
	char user_y;
	do {
		ask_coords(user_x, user_y, "place your starting tile");
	} while (!board.place_base(player ,int(user_x), int(user_y)));
}

void Game::place_tile(char player) {
	char user_x;
	char user_y;
	do {
		ask_coords(user_x, user_y, "place your tile");
	} while (!board.place_tile(tiles_queue.front(), user_x, user_y, player));
	Tile temp_tile = tiles_queue.front();
	tiles_queue.pop();
	tiles_queue.push(temp_tile);
}