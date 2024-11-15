#pragma once
#include <string>

class Player {
public:
	Player(std::string n, char c);
	~Player();
	std::string get_name();
	char get_char();
private:
	char character;
	std::string name;
	int exchange_number;
};