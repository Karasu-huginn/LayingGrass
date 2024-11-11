#include "Player.h"

Player::Player(std:: string n, int c) {
	name = n;
	color = Color(c);
}

Player::~Player() {

}

std::string Player::colorize(std::string text) {
	return color.colorize_text(text);
}

std::string Player::get_name() {
	return name;
}