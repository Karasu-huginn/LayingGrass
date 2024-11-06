#include "Color.h"

Color::Color() {
	color = "white";
	init_indexes();
}

Color::Color(std::string c) {
	color = c;
	init_indexes();
}

std::string Color::colorize_text(std::string text) {
	return "\033[" + indexes[color] + "m" + text + "\033[0m";
}

void Color::init_indexes() {
	indexes["black"] = "30";
	indexes["red"] = "31";
	indexes["green"] = "32";
	indexes["yellow"] = "33";
	indexes["blue"] = "34";
	indexes["magenta"] = "35";
	indexes["cyan"] = "36";
	indexes["white"] = "37";
}