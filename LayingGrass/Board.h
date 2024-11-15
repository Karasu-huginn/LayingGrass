#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include "Color.h"

class Board {
public:
	Board();
	Board(int pn);
	~Board();
	void init_bonuses();
	void set_bonuses(int bonus_num, char bonus_char);
	void display_board_x_coords();
	void display_board_char(int x, int y);
	void display_board();
	void check_victory();
	void place_tile();
	void rob_tile();
	bool place_stone(int x, int y);
	bool check_neighborhood(int x, int y, char goal);
	char bonus_check();

private:
	std::vector<std::vector<char>> board;
	Color color;
	int board_size;
	int player_number;
};