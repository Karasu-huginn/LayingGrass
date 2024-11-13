#include "Tile.h"

Tile::Tile() {

	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			shape[x][y] = 0;
		}
	}
}

Tile::Tile(nlohmann::json d) {
	std::string cell;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			cell = d[x][y].dump();
			std::istringstream(cell) >> shape[x][y];	// converts and store string data to bool
		}
	}
}

Tile::~Tile() {

}

void Tile::display() {
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			if (shape[x][y]) {
				std::cout << "O";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
}



void Tile::display_row(int row) {
	for (int y = 0; y < 6; y++) {
        if (shape[row][y]) {
            std::cout << "O";
        } else {
            std::cout << " ";
        }
    }
}