#pragma once
#include "Color.h"

class Player {
public:
	Player(std::string n, int c);
	~Player();
	std::string colorize(std::string text);
	std::string get_name();
private:
	Color color;
	std::string name;
};