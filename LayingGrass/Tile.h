#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <sstream>
#include <string>

class Tile {
public:
	Tile();
	Tile(nlohmann::json d);
	~Tile();
	void display();
	void display_row(int row);
private:
	bool shape[6][6];
};