#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
using ll = unsigned long long;

ll T, n, a[maxn], cur[maxn], pre[maxn], suf[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 1; i < n; i++) {
			std::cin >> a[i];
		}
		pre[0] = cur[0] = 0;
		for (int i = 1; i < n; i++) {
			cur[i] = cur[i-1] + a[i];
		}
		ll l = -1, r = n, m, left = 1LL, right = 1LL;
		ll ans = 0, tot = 0;
		for (int i = 1; i <= n; i++) {
			if (i%2==1) {
				l++;
				ans += tot;
			} else {
				r--;
				tot += cur[r]-cur[l];
				ans += tot;
			}
			std::cout << ans << " \n"[i==n];
		}
	}
}