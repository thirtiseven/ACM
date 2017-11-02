#include <iostream>
#include <string>
#include <cstring>

int colour[55][55];
int dir[9] = {-1, 0, 1};
int cnt = 1;
int n, m;
std::string sa[55];

int dfs(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) {
		return 0;
	}
	if(colour[x][y]) {
		return 0;
	}
	if(sa[x][y] == 'W') {
		return 0;
	}
	colour[x][y] = cnt;
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
	return 1;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> sa[i];
	}
	memset(colour, 0, sizeof(colour));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(sa[i][j] == 'L') {
				cnt += dfs(i, j);
			}
		}
	}
	std::cout << cnt-1 << '\n';
	return 0;
}