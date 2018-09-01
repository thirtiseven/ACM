#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		ll mx,my,n, x, y;
		std::cin >> mx >> my >> n;
		ll ans = 0;
		for (int i= 0; i < n; i++) {
			std::cin >> x >> y;
			ans += std::min(std::min(x, y), std::min(mx-x, my-y));
		}
		std::cout << ans << '\n';
	}
}