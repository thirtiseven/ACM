#include <iostream>
#include <algorithm>
#include <set>

using ll = long long;

const ll maxn = 321;

ll n, d, a[maxn];
std::multiset<ll> ss;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll T; std::cin >> T;
	for (ll _ = 1; _ <= T; _++) {
		std::cin >> n >> d;
		for (ll i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		std::cout << "Case #" << _ << ": ";
		ll ans;
		if (d == 2) {
			ans = 1;
			for (ll i = 0; i < n-1; i++) {
				if (a[i] == a[i+1]) {
					ans = 0;
					break;
				}
			}
		} else {
			ans = 2;
			for (ll i = 0; i < n-2; i++) {
				if (a[i] == a[i+1] && a[i] == a[i+2]) {
					ans = 0;
					break;
				}
			}
			if (ans == 2) {
				ss.clear();
				for (ll i = 0; i < n; i++) {
					ss.insert(a[i]);
				}
				for (ll i = 0; i < n; i++) {
					if (ss.count(2ll*a[i]) != 0) {
						ans = 1;
						break;
					}
				}
			}
		}
		std::cout << ans << '\n';
	}
}