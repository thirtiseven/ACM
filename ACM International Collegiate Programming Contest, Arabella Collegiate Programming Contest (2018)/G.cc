#include <iostream>
#include <algorithm>

const int maxn = 503;
int g[maxn][maxn], ul[maxn][maxn], ur[maxn][maxn], dl[maxn][maxn], dr[maxn][maxn];
int T;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> T;
	while (T--) {
		int n, m; 
		std::cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> g[i][j];
				ul[i][j] = g[i][j];
				ur[i][j] = g[i][j];
				dl[i][j] = g[i][j];
				dr[i][j] = g[i][j];
			}
		}
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (i && ul[i - 1][j])
					ul[i][j] = std::max(ul[i][j], ul[i - 1][j]);
				if (j && ul[i][j - 1])
					ul[i][j] = std::max(ul[i][j], ul[i][j - 1]);
				if (i && j && ul[i - 1][j - 1])
					ul[i][j] = std::max(ul[i][j], ul[i - 1][j - 1]);
			}

		for (int i = 0; i < n; ++i)
			for (int j = m - 1; j >= 0; --j) {
				if (i && ur[i - 1][j])
					ur[i][j] = std::max(ur[i][j], ur[i - 1][j]);
				if (j < m - 1 && ur[i][j + 1])
					ur[i][j] = std::max(ur[i][j], ur[i][j + 1]);
				if (i && j < m - 1 && ur[i - 1][j + 1])
					ur[i][j] = std::max(ur[i][j], ur[i - 1][j + 1]);
			}

		for (int i = n - 1; i >= 0; --i)
			for (int j = 0; j < m; ++j) {
				if (i < n - 1 && dl[i + 1][j])
					dl[i][j] = std::max(dl[i][j], dl[i + 1][j]);
				if (j && dl[i][j - 1])
					dl[i][j] = std::max(dl[i][j], dl[i][j - 1]);
				if (i < n - 1 && j && dl[i + 1][j - 1])
					dl[i][j] = std::max(dl[i][j], dl[i + 1][j - 1]);
			}

		for (int i = n - 1; i >= 0; --i)
			for (int j = m - 1; j >= 0; --j) {
				if (i < n - 1 && dr[i + 1][j])
					dr[i][j] = std::max(dr[i][j], dr[i + 1][j]);
				if (j < m - 1 && dr[i][j + 1])
					dr[i][j] = std::max(dr[i][j], dr[i][j + 1]);
				if (i < n - 1 && j < m - 1 && dr[i + 1][j + 1])
					dr[i][j] = std::max(dr[i][j], dr[i + 1][j + 1]);
			}

		int r = INT_MAX;
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				int mx = 0, mn = INT_MAX;

				mx = std::max(mx, ul[i - 1][j - 1]);
				mn = std::min(mn, ul[i - 1][j - 1]);

				mx = std::max(mx, ur[i - 1][j + 1]);
				mn = std::min(mn, ur[i - 1][j + 1]);

				mx = std::max(mx, dl[i + 1][j - 1]);
				mn = std::min(mn, dl[i + 1][j - 1]);

				mx = std::max(mx, dr[i + 1][j + 1]);
				mn = std::min(mn, dr[i + 1][j + 1]);

				r = std::min(r, mx - mn);
			}
		}
		std::cout << r << '\n';
	}
}