#include "Player.h"

Player::Player(std:: string n, char c) {
	name = n;
	character = 'a' + c;
	exchange_number = 0;
}

Player::~Player() {

}


std::string Player::get_name() {
	return name;
}

int Player::get_exchange_number() {
	return exchange_number;
}

void Player::increment_exchange_number() {
    exchange_number++;
}

void Player::decrement_exchange_number() {
    exchange_number--;
}

char Player::get_char() {
	return character;
}