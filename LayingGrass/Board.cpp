#include "Board.h"

Board::Board() {

}

Board::Board(int pn) {
	player_number = pn;
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
	set_bonuses(exchange_num, 'E');
	set_bonuses(stone_num, 'S');
	set_bonuses(rob_num, 'R');
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

void Board::display_board() {
	char letter = 'A';
	std::cout << " \t";
	for (int i = 0; i < board_size; i++) {
		std::cout << letter << " ";
		letter++;
	}
	std::cout << "\n" << std::endl;
	for (int x = 0; x < board_size; x++) {
		std::cout << x << "\t";
		for (int y = 0; y < board_size; y++) {
			std::cout << board[x][y] << " ";
		}
		std::cout << std::endl;
	}

}

void Board::check_victory() {

}

void Board::place_tile() {

}

void Board::rob_tile() {

}

void Board::place_stone() {

}

bool Board::check_neighborhood() {
	return false;
}

char Board::bonus_check() {
	return ' ';
}