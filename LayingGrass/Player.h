#pragma once
#include "Color.h"

class Player {
public:
	Player();
	~Player();
	Color get_color();
	std::string get_name();
private:
	Color color;
	std::string name;
};