#pragma once
#include <string>

class Player {
public:
	Player(std::string n);
	~Player();
	std::string get_name();
private:
	std::string name;
	int exchange_number;
};