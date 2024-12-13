#include "Board.h"

Board::Board() {
}

Board::Board(int pn) {
	player_number = pn;
	color = Color(0);
	if (player_number < 5) {
		board_size = 20;
	}
	else {
		board_size = 30;
	}

	for (int x = 0; x < board_size; x++) {
		std::vector<char> line;
		for (int y = 0; y < board_size; y++) {
			line.push_back('0');
		}
		board.push_back(line);
	}
	init_bonuses();
	display_board();
}

Board::~Board() {

}

void Board::init_bonuses() {
	int exchange_num = ceil(player_number * 1.5);
	int stone_num = ceil(player_number * 0.5);
	int rob_num = player_number;
	set_bonuses(exchange_num, '1');
	set_bonuses(stone_num, '2');
	set_bonuses(rob_num, '3');
}

void Board::set_bonuses(int bonus_num, char bonus_char) {
	int x, y;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, board_size-1);

	for (int i = 0; i < bonus_num; i++) {
		do {
		x = dist(mt);
		y = dist(mt);
		} while (board[x][y] != '0');
		board[x][y] = bonus_char;
	}
}

void Board::display_board_x_coords() {
	char letter = 'A';
	std::cout << " \t";
	for (int i = 0; i < board_size; i++) {
		if (letter > 'Z') {
			std::cout << char(letter + 6) << " ";
		}
		else {
			std::cout << letter << " ";
		}
		letter++;
	}
}

void Board::display_board_char(int x, int y) {
	if (board[x][y] == '0') {
		std::cout << '.' << " ";
	}
	else if (board[x][y] == '1') {
		std::cout << "E ";
	}
	else if (board[x][y] == '2') {
		std::cout << "S ";
	}
	else if (board[x][y] == '3') {
		std::cout << "R ";
	}
	else if ('A' <= board[x][y] and board[x][y] <= 'Z') {
		color.color_set(int(board[x][y]) - 'A');
		std::cout << color.colorize_text("0 ");
	}
	else if ('a' <= board[x][y] and board[x][y] <= 'z') {
		color.color_set(int(board[x][y] - 'a'));
		std::cout << color.colorize_text("O ");
	}
	else {
		std::cout << board[x][y] << " ";
	}
}

void Board::display_board() {
	display_board_x_coords();
	char letter = 'A';
	std::cout << "\n" << std::endl;
	for (int x = 0; x < board_size; x++) {
		if (letter+x > 'Z') {
			std::cout << char(letter + x + 6) << "\t";
		}
		else {
			std::cout << char(letter + x) << "\t";
		}
		for (int y = 0; y < board_size; y++) {
			display_board_char(x, y);
		}
		std::cout << std::endl;
	}

}

int Board::count_grass(char player) {
	int grass_number = 0;
	for (int x = 0; x < board_size; x++) {
		for (int y = 0; y < board_size; y++) {
			if (board[x][y] == player or board[x][y] == char(player + 32)) {
				grass_number++;
			}
		}
	}
	return grass_number;
}

int Board::count_square(int x, int y, char player) {
	int counter = 0;
	while (counter < board_size+x and counter < board_size+y) {
		for (int i = 0; i < counter; i++) {
			for (int j = 0; j < counter; j++) {
				if (x + i >= board_size or y + j >= board_size) {
					continue;
				}
				if (board[x + i][y + j] != player and board[x + i][y + j] != char(player + 32))
				{
					return --counter;
				}
			}
		}
		counter++;
	}
	return 0;
}

void Board::check_victory(int &score, int &winning_player) {
	int temp_score;
	for (char character = 'A'; character < char('A' + player_number); character++) {
		for (int x = 0; x < board_size; x++) {
			for (int y = 0; y < board_size; y++) {
				if (board[x][y] != character and board[x][y] != character + 32) {
					continue;
				}
				temp_score = count_square(x, y, character);
				if (temp_score < score) {
					continue;
				}
				else if (temp_score == score) {
					if (count_grass(character) < count_grass(char(winning_player + 'A'))) {
						continue;
					}
				}
				score = temp_score;
				winning_player = int(character - 'A');
			}
		}
	}
}

bool Board::place_base(char player, int x, int y) {
	if (board[x][y] == '0') {
		board[x][y] = char(player-32);
		return true;
	}
	else {
		return false;
	}
}

bool Board::is_enemy_close(int x, int y, char player) {
	for (char character = 'A'; character < 'A' + player_number; character++) {
		if (character != player-32) {
			if (check_neighborhood(x, y, character)) {
				return true;
			}
		}
	}
	for (char character = 'a'; character < 'a' + player_number; character++) {
		if (character != player) {
			if (check_neighborhood(x, y, character)) {
				return true;
			}
		}
	}
	return false;
}

bool Board::can_place_tile(Tile tile, int x, int y, char player) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (tile.get_cell(i, j)) {
				if (board[x + i][y + j] != '0') {
					return false;
				}
				if (is_enemy_close(x+i, y+j, player)) {
					return false;
				}
				if (check_neighborhood(x + i, y + j, player)) {
					return true;
				}
				if (check_neighborhood(x + i, y + j, player - 32)) {
					return true;
				}
			}
		}
	}
	return false;
}

void Board::tile_apply(Tile tile, int x, int y, char player) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (tile.get_cell(i, j)) {
				board[x + i][y + j] = player;
			}
		}
	}
}

bool Board::place_tile(Tile tile, int x, int y, char player) {
	if (!can_place_tile(tile, x, y, player)) {
		return false;
	}
	if (x >= board_size - 5 or y >= board_size - 5) {
		return false;
	}
	tile_apply(tile, x, y, player);
	return true;
	
}

bool Board::rob_tile(int x, int y, char player) {
	if (board[x][y] != player) {
		board[x][y] = player;
		return true;
	}
	return false;
}

bool Board::can_place_stone(Tile tile, int x, int y) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (tile.get_cell(i, j)) {
				if (board[x + i][y + j] != '0') {
					return false;
				}
			}
		}
	}
	return true;
}

bool Board::place_stone(Tile tile, int x, int y) {
	if (x >= board_size - 5 or y >= board_size - 5) {
		return false;
	}
	if (!can_place_stone(tile, x, y)) {
		return false;
	}
	tile_apply(tile, x, y, '$');
	return true;
}

bool Board::buy_grass_tile(int x, int y, char player) {
	if (board[x][y] == '0') {
		board[x][y] = player;
        return true;
	} else {
		return false;
	}
}

bool Board::check_neighborhood(int x, int y, char goal) {
	if (x + 1 < board_size and board[x + 1][y] == goal) {
		return true;
	}
	if (x - 1 >= 0 and board[x - 1][y] == goal) {
		return true;
	}
	if (y + 1 < board_size and board[x][y + 1] == goal) {
		return true;
	}
	if (y - 1 >= 0 and board[x][y - 1] == goal) {
		return true;
	}
	// check north, south, east, west for char goal contact
	return false;
}
bool Board::check_full_neighborhood(int x, int y, char goal) {
	if (x + 1 < board_size and board[x + 1][y] != goal) {
		return false;
	}
	if (x - 1 >= 0 and board[x - 1][y] != goal) {
		return false;
	}
	if (y + 1 < board_size and board[x][y + 1] != goal) {
		return false;
	}
	if (y - 1 >= 0 and board[x][y - 1] != goal) {
		return false;
	}
	// check north, south, east, west for char goal full contact
	return true;
}


void Board::get_bonus(Player &player) {
	char player_char = player.get_char();
	for (int x = 0; x < board_size; x++){
		for (int y = 0; y < board_size; y++){
			if (board[x][y] == '1' and check_full_neighborhood(x, y, player_char)) {
				player.add_exchange();
				board[x][y] = player_char;
			}
			if (board[x][y] == '2' and check_full_neighborhood(x, y, player_char)) {
				player.add_stone();
				board[x][y] = player_char;
			}
			if (board[x][y] == '3' and check_full_neighborhood(x, y, player_char)) {
				player.add_rob();
				board[x][y] = player_char;
			}
		}
	}
}