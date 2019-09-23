#include <iostream>
using ll = long long;

int main(int argc, char *argv[]) {  
	ll n, a[23];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= (1<<n); i++) {
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			if (i>>(j) & 1) {
				cur |= a[j];
			}
		}
		ans += cur;
	}
	std::cout << ans << '\n';
}