#include <iostream>
#include <algorithm>

const int maxn = 5000;

int main(int argc, char *argv[]) {  
	int n, m, p[maxn], r[maxn];
	std::pair<int, int> s[maxn];
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i].first;
		s[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> r[i];
	}
	int ans[maxn];
	std::sort(s, s+n);
	int vis[maxn];
	std::fill(vis, vis+maxn, 0);
	bool yes = 1;
	for (int i = n-1; i>=0; i--) {
		int now = -1, cost = maxn;
		for (int j = 0; j < m; j++) {
			if (!vis[j] && p[j] >= s[i].first && r[j] < cost) {
				cost = r[j];
				now = j;
			}
		}
		if (now == -1) {
			yes = 0;
		}
		ans[s[i].second] = now;
		vis[now] = 1;
	}
	if (yes) {
		for (int i = 0; i < n; i++) {
			std::cout << ans[i]+1 << ' ';
		}
	} else {
		std::cout << "impossible\n";
	}
}