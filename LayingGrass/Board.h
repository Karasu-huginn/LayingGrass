#pragma once
#include <vector>

class Board {
public:
	Board();
	Board(int pn);
	~Board();
	void display_board();
	void check_victory();
	void place_tile();
	void rob_tile();
	void place_stone();
	bool check_neighborhood();
	char bonus_check();

private:
	std::vector<std::vector<char>> board;
};