#include <iostream>
#include <vector>

bool valid(int(&arr)[9][9], int x, int y, int n); 
int solve(); 
bool newRulesValid1();
bool newRulesValid2();


int field[9][9] = {
					{0, 0, 0,   0, 0, 0,   0, 0, 0},
					{0, 0, 0,   0, 0, 0,   0, 0, 0},
					{0, 0, 0,   0, 0, 0,   0, 0, 0},

					{0, 0, 0,   0, 0, 0,   0, 0, 0},
					{0, 0, 1,   0, 0, 0,   0, 0, 0},
					{0, 0, 0,   0, 0, 0,   2, 0, 0},

					{0, 0, 0,   0, 0, 0,   0, 0, 0},
					{0, 0, 0,   0, 0, 0,   0, 0, 0},
					{0, 0, 0,   0, 0, 0,   0, 0, 0} };



int main() {

	solve(); 

	return 0; 
}


bool valid(int(&arr)[9][9], int x, int y, int n) {

	for (int i = 0; i < 9; i++) {
		if (arr[y][i] == n) {
			return false;
		}

		if (arr[i][x] == n) {
			return false;
		}
	}

	int x0 = (int)((double)x / 3) * 3;
	int y0 = (int)((double)y / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int i2 = 0; i2 < 3; i2++) {
			if (arr[y0 + i][x0 + i2] == n) {
				return false;
			}
		}
	}

	return true;
}



int solve() {

	for (int i = 0; i < 9; i++) {
		for (int i2 = 0; i2 < 9; i2++) {
			if (field[i][i2] == 0) {
				for (int i3 = 1; i3 < 10; i3++) {
					if (valid(field, i2, i, i3)) {
						field[i][i2] = i3;
						solve();
						field[i][i2] = 0;
					}
				}
				return 0;
			}
		}
	}


	if (newRulesValid1()) {
		for (int(&a)[9] : field) {
			for (int i : a) {
				std::cout << i << "  ";
			}
			std::cout << std::endl;
		}

		std::cin.get();
	}



	return 0;
}

bool newRulesValid2() {

	bool valid = true; 

	for (int i = 0; i < 9; i++) {
		for (int i2 = 0; i2 < 9; i2++) {
			if (i > 0) {
				if (field[i][i2] == field[i - 1][i2] + 1 || field[i][i2] == field[i - 1][i2] - 1) {
					valid = false;
				}
			}

			if (i < 8) {
				if (field[i][i2] == field[i + 1][i2] + 1 || field[i][i2] == field[i + 1][i2] - 1) {
					valid = false;
				}
			}

			if (i2 > 0) {
				if (field[i][i2] == field[i][i2 - 1] + 1 || field[i][i2] == field[i][i2 - 1] - 1) {
					valid = false;
				}
			}

			if (i2 < 8) {
				if (field[i][i2] == field[i][i2 + 1] + 1 || field[i][i2] == field[i][i2 + 1] - 1) {
					valid = false;
				}
			}

		}
	}

	return valid; 
}


bool newRulesValid1() {

	bool valid = true; 


	//Kings move
	for (int i = 0; i < 9; i++) {

		for (int i2 = 0; i2 < 9; i2++) {

			for (int y = i-1; y < i + 2; y++) {
				for (int x = i2-1; x < i2 + 2; x++) {
					if (x >= 0 && y >= 0 && y < 9 && x < 9) {
						if (y != i || x != i2) {
							if (field[y][x] == field[i][i2]) {
								valid = false;
							}
						}
					}
				
				}
			}

		}

	}



	return valid; 
}

/*


adjacent no consecutive - done

kings move no same - done

knights no same 


*/