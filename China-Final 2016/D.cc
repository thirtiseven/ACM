#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e6+7;

using ll = long long;

ll b[maxn];
ll n, k;

bool check(ll p) {
	if (p == 0) return 1;
	std::vector<ll> now(p+1);
	std::fill(now.begin(), now.end(), 0);
	ll cnt = 0;
	ll num = 1;
	for (int i = 0; i < p; i++) {
		now[i] = b[i];
	}
	for (int i = p; i < n; i++) {
		if (b[i] >= now[cnt]*2LL) {
			now[cnt] = b[i];
			cnt++;
			if (cnt >= p) {
				num ++;
				cnt = 0;
			}
		}
	}
	return num >= k;
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll T;
	std::cin >> T;
	for (int CC = 1; CC <= T; CC++) {
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		std::sort(b, b+n);
		ll l = 0, r = n/k, mid;
		ll ans = 0;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				ans = std::max(ans, mid);
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		std::cout << "Case #" << CC << ": " << ans << '\n';
	}
}