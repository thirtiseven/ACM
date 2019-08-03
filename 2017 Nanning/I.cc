#include <iostream>

const int maxn = 100086;
const int INF = 0x3f3f3f3f;

int mp[5][5], ans, k;

inline void rotate(int x, int y) {
	ans += mp[x][y];
	ans += mp[x + 1][y];
	ans += mp[x][y + 1];
	ans += mp[x + 1][y + 1];

	int t = mp[x][y];
	mp[x][y] = mp[x][y + 1];
	mp[x][y + 1] = mp[x + 1][y + 1];
	mp[x + 1][y + 1] = mp[x + 1][y];
	mp[x + 1][y] = t;
}

inline void unrotate(int x, int y) {
	ans -= mp[x][y];
	ans -= mp[x + 1][y];
	ans -= mp[x][y + 1];
	ans -= mp[x + 1][y + 1];
	
	int t = mp[x][y];
	mp[x][y] = mp[x + 1][y];
	mp[x + 1][y] = mp[x + 1][y + 1];
	mp[x + 1][y + 1] = mp[x][y + 1];
	mp[x][y + 1] = t;
}

int dfs(int t, int alpha, int beta) {
	if (t > 2 * k) {
		return ans;
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			rotate(i, j);
			if (t & 1) {
				int cnt = dfs(t + 1, alpha, beta);
				alpha = alpha > cnt ? alpha : cnt;
				unrotate(i, j);
			} else {
				int cnt = dfs(t + 1, alpha, beta);
				beta = beta > cnt ? cnt : beta;
				unrotate(i, j);
			}
			if (beta <= alpha) return t & 1 ? alpha : beta;
		}
	}
	return t & 1 ? alpha : beta;
}

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> k;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				std::cin >> mp[i][j];
			}
		}
		ans = 0;
		std::cout << dfs(1, -INF, INF) << '\n';
	}
}