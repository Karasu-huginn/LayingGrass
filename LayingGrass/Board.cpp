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

void Board::check_victory() {
	for (char character = 'A'; character < char('A' + player_number); character++) {

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
	if (can_place_tile(tile, x, y, player)) {
		tile_apply(tile, x, y, player);
		return true;
	}
	else {
		return false;
	}
}

void Board::rob_tile() {

}

bool Board::place_stone(int x, int y) {
	if (board[x][y] == '0') {
		board[x][y] = '$';
		return true;
	}
	else {
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




char Board::bonus_check() {
	return ' ';
}








/*bool Board::check_neighborhood(int ox, int oy, char goal) {
	for (int nx = -1; nx < 2; nx++) {
		for (int ny = -1; ny < 2; ny++) {
			// unwanted cases skip
			if (nx == 0 and ny == 0) {
				continue;
			}
			if (ox + nx < 0) {
				continue;
			}
			if (ox + nx >= board_size) {
				continue;
			}
			if (oy + ny < 0) {
				continue;
			}
			if (oy + ny >= board_size) {
				continue;
			}

			// wanted cases check
			if (board[ox + nx][oy + ny] == goal) {
				return true;
			}
		}
	}
}*/