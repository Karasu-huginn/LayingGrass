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
	void deep_copy(bool(&tmp_sh)[6][6]);
	void deep_paste(bool(tmp_sh)[6][6]);
	void flip_h();
	void flip_v();
	void rotate();
private:
	bool shape[6][6];
};