#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 100000+7;

std::vector<int> g[maxn];

int T;
int n, m, u, v;

int main(int argc, char *argv[]) {
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			g[i].clear();
		}
		while (m--) {
			std::cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool complete = 1, even = 1;
		for (int i = 1; i <= n; i++) {
			if (g[i].size() != n) {
				complete = 0;
			}
			if (g[i].size() % 4 == 2) {
				even = 0;
			}
		}
		if (complete == 0 && even == 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}