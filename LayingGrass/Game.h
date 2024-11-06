#pragma once
#include "Tile.h"
#include "Board.h"

class Game {
public:
	Game(int pn);
	~Game();
	void init_tiles_queue();
	void game_start();
private:
	std::vector<Tile> tiles_queue;
	Board board;
	int player_turn;
};