#pragma once
#include <iostream>
#include <map>

class Color {
public:
	Color();
	Color(int c);
	std::string colorize_text(std::string text);
	void init_indexes();
private:
	int color;
	std::map<int, std::string> indexes;
};

