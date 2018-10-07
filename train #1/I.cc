#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 54;
const int inf = 10000000;

int d[maxn][maxn];
int lowc[maxn];
int vis[maxn];

int prim(int n) {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= n; i++) {
		lowc[i] = d[1][i];
	}
	vis[1] = 1;
	for (int i = 1; i < n; i++) {
		int minc = inf;
		int p = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && minc > lowc[j]) {
				minc = lowc[j];
				p = j;
			}
		}
		vis[p] = 1;
		ans += minc;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && lowc[j] > d[p][j]) {
				lowc[j] = d[p][j];
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {  
	int n, m;
	while (std::cin >> n) {
		if (n == 0) break;
		std::cin >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				d[i][j] = inf;
			}
		}
		int u, v, w;
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v >> w;
			if (d[u][v] == 0 && d[v][u] == 0) {
				d[u][v] = w;
				d[v][u] = w;
			} else {
				d[u][v] = std::min(d[u][v], w);
				d[v][u] = std::min(d[u][v], w);
			}
		}
		std::cout << prim(n) << '\n';
	}
}