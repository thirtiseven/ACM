#include <iostream>
#include <algorithm>

const int maxn = 3e5+7;
using ll = long long;

ll n, m, b[maxn], w[maxn];
ll t, l, r, c;
ll ans = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> t >> l >> r >> c;
		ll all = c, opt = 0;
		if (t == 1) {
			for (int j = l-1; j <= r-1; j++) {
				all += b[j];
			}
		} else {
			for (int j = l-1; j <= r-1; j++) {
				all += w[j];
			}
		}
		for (int j = l-1; j <= r-1; j++) {
			opt += std::max(w[j], b[j]);
			w[j] = b[j] = 0;
		}
		ans += std::max(all, opt);
	}
	for (int i = 0; i < n; i++) {
		ans += std::max(w[i], b[i]);
	}
	std::cout << ans << '\n';
}