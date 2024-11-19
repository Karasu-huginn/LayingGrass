#pragma once
#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <queue>
#include "nlohmann/json.hpp"
#include <fstream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <windows.h>

class Game {
public:
	Game(int pn);
	~Game();
	void init_players();
	void init_tiles_queue();
	void tiles_queue_randomize(nlohmann::json data);
	void generate_rand_ind(int(&rand_tile_ind)[96]);
	bool queue_has_number(int number, int rand_tile_ind[96]);
	void display_current_next_tiles_queued(std::queue<Tile> queue);
	int display_turn_actions(int exchange_number);
	void game_loop();
	void interpret_coords(char& x, char& y);
	void ask_coords(char& user_x, char& user_y, std::string text);
	void place_stone();
	void rob_tile(char player);
	void bases_placement();
	void place_base(char player);
	void place_tile(char player);
	void clear_terminal();
	bool make_action(int action);
	void game_start();
	void exchange_tile();
	void game_last_actions(std::vector<Player> &players);
	void buy_grass_tile(char player);
	int input_int(int min, int max, std::string text);
	void input_string(char &user_pos, std::string text);
	void display_ending_turn();
	void clear_cin();
	void check_bonus_playability(Player &player);
private:
	int tiles_number;
	int players_number;
	std::queue<Tile> tiles_queue;
	Board board;
	std::vector<Player> players;
	int player_turn;
	Color color;
};