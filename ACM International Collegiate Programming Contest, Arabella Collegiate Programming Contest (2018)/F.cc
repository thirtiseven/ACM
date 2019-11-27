#include <iostream>
#include <algorithm>

using ll = long long;

ll f[30];

int main(int argc, char *argv[]) {  
	ll T;
	std::cin >> T;
	while (T--) {
		ll ans1 = 0, ans2 = 10000000000, one = 0;
		for (ll i = 1; i <= 26; i++) {
			std::cin >> f[i];
			if (f[i] >= 2) {
				ans1 += 2;
				ans2 = std::min(f[i]/2ll, ans2);
			}
			if (f[i] == 1) {
				one++;
			}
		}
		if (one) {
			ans1++;
			ans2 = std::min(ans2, one);
 		}
		if (ans1 == 0 && one > 0) {
			ans1 = 1, ans2 = one;
		} else if (ans1 == 0) {
			ans2 = 0;
		}
		std::cout << ans1 << ' ' << ans2 << '\n';
	}
}