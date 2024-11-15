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

void Board::place_tile() {

}

void Board::rob_tile() {

}

bool Board::place_stone(int x, int y) {
	std::cout << "x = " << x << " | y = " << y << std::endl;
	if (board[x][y] == '0') {
		board[x][y] = '$';
		return true;
	}
	else {
		return false;
	}
}

bool Board::check_neighborhood(int ox, int oy, char goal) {
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