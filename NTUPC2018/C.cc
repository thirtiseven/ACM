#include <iostream>
#include <algorithm>

const int maxn = 123;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
int map[maxn][maxn], dp[maxn][maxn];

int dfs(int x,int y) {
	int tx, ty, i;
	if(dp[x][y]) {
		return dp[x][y];
	}
	for (i =  0;i < 4;i++) {
		tx = x + dir[i][0], ty = y + dir[i][1];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] < map[x][y]) {
			int temp = dfs(tx,ty);
			if(dp[x][y] <= temp) {   
				dp[x][y] = temp+1;    
			}
		}
	}
	return dp[x][y];
}

int main(int argc, char *argv[]) {
	int t;
	while (std::cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> map[i][j];
				dp[i][j] = 0;
			}
		}
		int maxx = -1;
		for (int i = 0 ;i < n;i++) {
			for (int j = 0;j < m;j++) {
				t = dfs(i,j);
				maxx = std::max(maxx, t);
			}
		}
		std::cout << maxx + 1 << std::endl;
	}
}