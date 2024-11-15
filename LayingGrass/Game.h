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
	int display_turn_actions();
	void game_start();
	void interpret_coords(char& x, char& y);
	void place_stone();
	void bases_placement();
	void place_base(char player);
private:
	int tiles_number;
	int players_number;
	std::queue<Tile> tiles_queue;
	Board board;
	std::vector<Player> players;
	int player_turn;
};