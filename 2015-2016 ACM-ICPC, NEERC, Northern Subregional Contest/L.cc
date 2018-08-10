#include <iostream>
#include <algorithm>
#include <fstream>

int main(int argc, char *argv[]) { 
	std::ofstream fout ("lucky.out"); 
	std::ifstream fin ("lucky.in");  
	int r, c;
	int mp[101][101];
//	std::cin >> r >> c;
	fin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
//			std::cin >> mp[i][j];
			fin >> mp[i][j];
		}
	}
	int ans = 0;
	int maxx = 0;
	for (int i = 0; i < r; i++) {
		maxx = mp[i][0];
		for (int j = 1; j < c; j++) {
			if (mp[i][j] > maxx) {
				ans++;
				maxx = mp[i][j];
			}
		}
		maxx = mp[i][c-1];
		for (int j = c-2; j >= 0; j--) {
			if (mp[i][j] > maxx) {
				ans++;
				maxx = mp[i][j];
			}
		}
	}
	for (int j = 0; j < c; j++) {
		maxx = mp[0][j];
		for (int i = 1; i < r; i++) {
			if (mp[i][j] > maxx) {
				ans++;
				maxx = mp[i][j];
			}
		}
		maxx = mp[r-1][j];
		for (int i = r-2; i >= 0; i--) {
			if (mp[i][j] > maxx) {
				ans++;
				maxx = mp[i][j];
			}
		}
	}
//	std::cout << ans+r*2+c*2 << '\n';
	fout << ans+r*2+c*2 << '\n';

}