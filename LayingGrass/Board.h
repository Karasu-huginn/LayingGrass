#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include "Color.h"
#include "Tile.h"
#include "Player.h"

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
	int count_grass(char player);
	int count_square(int x, int y, char player);
	void check_victory(int& score, int& winning_player);
	bool place_base(char player, int x, int y);
	bool is_enemy_close(int x, int y, char player);
	bool can_place_tile(Tile tile, int x, int y, char player);
	void tile_apply(Tile tile, int x, int y, char player);
	bool place_tile(Tile tile, int x, int y, char player);
	bool rob_tile(int x, int y, char player);
	bool place_stone(Tile tile, int x, int y);
	bool can_place_stone(Tile tile, int x, int y);
	bool check_neighborhood(int x, int y, char goal);
	bool check_full_neighborhood(int x, int y, char goal);
	bool buy_grass_tile (int x, int y, char player);
	void get_bonus(Player &player);

private:
	std::vector<std::vector<char>> board;
	Color color;
	int board_size;
	int player_number;
};