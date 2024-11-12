#include "Board.h"

Board::Board() {

}

Board::Board(int pn) {
	if (pn < 5) {
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
	display_board();
}

Board::~Board() {

}

void Board::init_bonuses() {

}

void Board::display_board() {
	std::cout << " \t";
	for (int i = 0; i < board_size; i++) {
		std::cout << "A ";
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