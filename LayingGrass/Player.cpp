#include "Player.h"

Player::Player(std:: string n, char c) {
	name = n;
	character = 'a' + c;
}

Player::~Player() {

}


std::string Player::get_name() {
	return name;
}

char Player::get_char() {
	return character;
}