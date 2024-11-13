#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <random>

class Board {
public:
	Board();
	Board(int pn);
	~Board();
	void init_bonuses();
	void set_bonuses(int bonus_num, char bonus_char);
	void display_board();
	void check_victory();
	void place_tile();
	void rob_tile();
	void place_stone();
	bool check_neighborhood();
	char bonus_check();

private:
	std::vector<std::vector<char>> board;
	int board_size;
	int player_number;
};