#include <iostream>
#include <algorithm>
#include <cstring>

const int inf = 100 * 1000 + 10;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false); 
	int c, s, q, T = 0;
	while(std::cin >> c >> s >> q) {
		if(c == 0 && s == 0 && q == 0) {
			return 0;
		}
		int d[110][110], n = c;
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = inf;
			}
		}
		d[1][1] = 0;
		for(int i = 0; i < s; i++) {
			int u, v, w;
			std::cin >> u >> v >> w;
			d[u][v] = w;
			d[v][u] = w;
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					d[i][j] = std::min(d[i][j], std::max(d[i][k], d[k][j]));		
				}
			}
		}
		if(T) {
			std::cout << '\n';
		}
		T++;
		std::cout << "Case #" << T << '\n';
		for(int i = 0; i < q; i++) {
			int from, to;
			std::cin >> from >> to;
			if(d[from][to] >= inf) {
				std::cout << "no path\n";
			} else {
				std::cout << d[from][to] << '\n';
			}
		}
	}
	return 0;
}