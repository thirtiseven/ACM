#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string c[26];
std::vector<std::pair<int, int>> ans;
char next;
int black, white;

//bool check(int x, int y) {
//	if (x >= 4 && c[x-1][y] == next && c[x-2][y] == next && c[x-3][y] == next && c[x-4][y] == next) {
//		return 1;
//	}
//	if (x <= 20 && c[x+1][y] == next && c[x+2][y] == next && c[x+3][y] == next && c[x+4][y] == next) {
//		return 1;
//	}
//	if (y >= 4 && c[x][y-1] == next && c[x][y-2] == next && c[x][y-3] == next && c[x][y-4] == next) {
//		return 1;
//	}
//	if (y <= 20 && c[x][y+1] == next && c[x][y+2] == next && c[x][y+3] == next && c[x][y+4] == next) {
//		return 1;
//	}
//	if (y >= 4 && x >= 4 && c[x-1][y-1] == next && c[x-2][y-2] == next && c[x-3][y-3] == next && c[x-4][y-4] == next) {
//		return 1;
//	}
//	if (y <= 20 && x <= 20 && c[x+1][y+1] == next && c[x+2][y+2] == next && c[x+3][y+3] == next && c[x+4][y+4] == next) {
//		return 1;
//	}
//	if (y >= 4 && x <= 20 && c[x+1][y-1] == next && c[x+2][y-2] == next && c[x+3][y-3] == next && c[x+4][y-4] == next) {
//		return 1;
//	}
//	if (y <= 20 && x >= 4 && c[x-1][y+1] == next && c[x-2][y+2] == next && c[x-3][y+3] == next && c[x-4][y+4] == next) {
//		return 1;
//	}
//	return 0;
//}

bool check(int x, int y) {
	if (c[x][y] != '.') {
		return 0;
	}
	c[x][y] = next;
	bool res = 0;
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 25; j++) {
			if (c[i][j] == next && c[i+1][j] == next && c[i+2][j] == next && c[i+3][j] == next && c[i+4][j] == next) {
				res = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 21; j++) {
			if (c[i][j] == next && c[i][j+1] == next && c[i][j+2] == next && c[i][j+3] == next && c[i][j+4] == next) {
				res = 1;
				break;
			}
		}
	}	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (c[i][j] == next && c[i+1][j+1] == next && c[i+2][j+2] == next && c[i+3][j+3] == next && c[i+4][j+4] == next) {
				res = 1;
				break;
			}
		}
	}
	for (int i = 4; i < 25; i++) {
		for (int j = 0; j < 21; j++) {
			if (c[i][j] == next && c[i-1][j+1] == next && c[i-2][j+2] == next && c[i-3][j+3] == next && c[i-4][j+4] == next) {
				res = 1;
				break;
			}
		}
	}
	c[x][y] = '.';
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	black = 0, white = 0;
	for (int i = 0; i < 25; i++) {
		std::cin >> c[i];
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (c[i][j] == 'o') {
				white++;
			} else if (c[i][j] == 'x') {
				black++;
			}
		}
	}
	if (black > white) {
		next = 'o';
	} else {
		next = 'x';
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (check(i, j)) {
				ans.push_back(std::make_pair(i, j));
			}
		}
	}
	if (ans.size() == 0) {
		std::cout << "tie\n";
	} else {
		for (auto it: ans) {
			std::cout << it.first << ' ' << it.second << '\n';
		}
	}
}