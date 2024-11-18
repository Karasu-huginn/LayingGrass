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

// refactor [] operator overload ?
char Tile::get_cell(int x, int y) {
	return shape[x][y];
}

void Tile::display() {
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			if (shape[x][y]) {
				std::cout << "0";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
}

void Tile::deep_copy(bool(&tmp_sh)[6][6]) {
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			tmp_sh[x][y] = shape[x][y];
		}
	}
}

void Tile::deep_paste(bool (tmp_sh)[6][6]) {
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			shape[x][y] = tmp_sh[x][y];
		}
	}
}

void Tile::flip_h() {
	bool temp_shape[6][6];
	deep_copy(temp_shape);
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			temp_shape[x][y] = shape[5-x][y];
		}
	}
	deep_paste(temp_shape);
}

void Tile::flip_v() {
	bool temp_shape[6][6];
	deep_copy(temp_shape);
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			temp_shape[x][y] = shape[x][5-y];
		}
	}
	deep_paste(temp_shape);
}

void Tile::rotate() {
	bool temp_shape[6][6];
	deep_copy(temp_shape);
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 6; y++) {
			temp_shape[x][y] = shape[y][5 - x];
		}
	}
	deep_paste(temp_shape);
}