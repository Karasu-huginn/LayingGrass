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
	void game_start();
	void tiles_queue_randomize(nlohmann::json data);
	void generate_rand_ind(int(&rand_tile_ind)[96]);
	bool queue_has_number(int number, int rand_tile_ind[96]);
	void display_current_next_tiles_queued(std::queue<Tile> queue);
private:
	int players_number;
	std::queue<Tile> tiles_queue;
	Board board;
	std::vector<Player> players;
	int player_turn;
};