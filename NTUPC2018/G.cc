#include <iostream>
#include <algorithm>

using ll = unsigned long long;
const ll maxn = 200009;

int main(int argc, char *argv[]) {  
	ll n, q, a[maxn], k[maxn], s[maxn];
	std::cin >> n >> q;
	for (ll i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	s[0] = a[0];
	for (ll i = 1; i < n; i++) {
		s[i] = s[i-1] + a[i];
	}
	ll sum = s[n-1];
	ll now = 0;
	for (ll i = 0; i < q; i++) {
		std::cin >> k[i];
		now += k[i];
		ll ans = n - (std::upper_bound(s, s+n, now) - s);
		if (ans == 0) {
			ans = n;
		}
		std::cout << ans << '\n';
		if (now >= sum) {
			now = 0;
		}
	}
}