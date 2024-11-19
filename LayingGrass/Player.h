#pragma once
#include <string>

class Player {
public:
	Player(std::string n, char c);
	~Player();
	std::string get_name();
	int get_exchange_number();

	void increment_exchange_number();
	void decrement_exchange_number();
	char get_char();
	void add_exchange();
	void add_stone();
	void add_rob();
	int get_stone_number();
	int get_rob_number();

private:
	char character;
	std::string name;
	int exchange_number;
	int rob_number;
	int stone_number;
};