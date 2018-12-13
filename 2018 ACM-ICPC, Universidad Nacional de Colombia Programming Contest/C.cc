#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 123;
const int inf = maxn*maxn*1000+10;

int idx(char c) {
	return int(c)-33;
}

int d[maxn][maxn];

int main(int argc, char *argv[]) {  
	int n = 100;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			d[i][j] = inf;
		}
	}
	for(int i = 0; i < n; i++) {
		d[i][i] = 0;
	}
	d[0][0] = 0;
	std::string s, t;
	std::cin >> s >> t;
	int T, cost;
	char u, v;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> u >> v >> cost;
		d[idx(u)][idx(v)] = std::min(cost, d[idx(u)][idx(v)]);
//		std::cout << d[idx(u)][idx(v)] << ' ';
	}
//	std::cout << '\n';
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
			}
		}
	}
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			std::cout << d[i][j] << " ";	
//		}
//		std::cout << '\n';
//	}
	int ans = 0;
	bool yes = 1;
	for (int i = 0; i < s.length(); i++) {
		if (d[idx(s[i])][idx(t[i])] >= inf) {
			yes = 0;
		}
//		std::cout << s[i] << " " << t[i] << " " << d[idx(s[i])][idx(t[i])] << '\n';
		ans += d[idx(s[i])][idx(t[i])];
	}
	if (yes == 0) ans = -1;
	std::cout << ans << '\n';
}