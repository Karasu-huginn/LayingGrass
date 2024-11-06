#pragma once
#include <iostream>
#include <map>

class Color {
public:
	Color();
	Color(std::string c);
	std::string colorize_text(std::string text);
	void init_indexes();
private:
	std::string color;
	std::map<std::string, std::string> indexes;
};

