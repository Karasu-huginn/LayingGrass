#include "Color.h"

Color::Color() {
	color = 0;
	init_indexes();
}

Color::Color(int c) {
	color = c;
	init_indexes();
}

void Color::color_set(int c) {
	color = c;
}

std::string Color::colorize_text(std::string text) {
	return "\033[" + indexes[color] + "m" + text + "\033[0m";
}

void Color::init_indexes() {
	indexes[0] = "91";
	indexes[1] = "92";
	indexes[2] = "93";
	indexes[3] = "94";
	indexes[4] = "95";
	indexes[5] = "96";
	indexes[6] = "31";
	indexes[7] = "32";
	indexes[8] = "33";
}