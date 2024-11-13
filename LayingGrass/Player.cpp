#include "Player.h"

Player::Player(std:: string n) {
	name = n;
}

Player::~Player() {

}


std::string Player::get_name() {
	return name;
}