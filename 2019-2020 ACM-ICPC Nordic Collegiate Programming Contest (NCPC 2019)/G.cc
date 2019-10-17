#include <iostream>

using ll = long long;

ll n, m, k;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	ll one = std::min(n, m);
	ll xxx = (n - one) % k;
	ll val = 1;
	if (xxx != 0) {
		val += xxx / one;
		xxx = xxx % one;
	}
	ll tim = (n-one)/k;
	ll ans = 0;
	ans += tim * n;
	ans -= (tim * k - k) * tim / 2;
	ans += xxx * (1 + xxx) / 2 * (val+1);
	ans += one * (1 + one) / 2 * val;
	std::cout << ans << '\n';
}