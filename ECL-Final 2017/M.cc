#include <iostream>

using ll = int;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		ll a, b, c, d, e;
		std::cin >> a >> b >> c >> d >> e;
		ll n, ans = 0, t;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> t;
			if (t>=1&&t<=48) {
				ans += a;
			} else if (t>=49&&t<=56) {
				ans += b;
			} else if (t>=57&&t<=60) {
				ans += c;
			} else if (t>=61&&t<=62) {
				ans += d;
			} else {
				ans += e;
			}
		}
		std::cout << "Case #" << CAS << ": " << ans << "0000\n";
	}
}