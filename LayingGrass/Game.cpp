#include "Game.h"

Game::Game(int pn) {
	std::cout << "Initializing Game..." << std::endl;
	players_number = pn;
	tiles_number = ceil(pn * 10.67);
	init_players();
	init_tiles_queue();
	board = Board(pn);
	player_turn = pn * 9;

	// for (int i = 0; i < 96; i++) {
	// 	Tile current_tile = tiles_queue.front();
	// 	current_tile.display();
	// 	tiles_queue.pop();
	// }
}

Game::~Game() {

}

void Game::init_players() {
	std::cout << "Initializing Players..." << std::endl;
	std::string name;
	for (int i = 0; i < players_number; i++) {
		std::cout << "Enter the name of the player " << i << " : " << std::endl;
		std::cin >> name;
		players.push_back(Player(name));
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

void Game::game_start() {
	//display_current_next_tiles_queued(tiles_queue);
	place_stone();
	board.display_board();

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

void Game::place_stone() {
	char user_x;
	char user_y;
	do {
	std::cout << "Please enter the coordinates of the square you'd like to place your stone on.\nx : ";
	std::cin >> user_y;
	std::cout << "y : ";
	std::cin >> user_x;
	interpret_coords(user_x, user_y);
	} while (!board.place_stone(int(user_x), int(user_y)));
}
