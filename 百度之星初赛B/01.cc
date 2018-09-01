#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 2e5+7;

int main(int argc, char *argv[]) {  
	int n, m, k, T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		int num[maxn];
		std::fill(num, num+maxn, 0);
		int u, v;
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v;
			num[u]++;
			num[v]++;
		}
		int maxx = 0;
		for (int i = 0; i < n; i++) {
			maxx = std::max(num[i], maxx);
		}
		std::cout << std::min(maxx+std::min(k, m-maxx)+(n-1-m), n-1) << '\n';
	}
}