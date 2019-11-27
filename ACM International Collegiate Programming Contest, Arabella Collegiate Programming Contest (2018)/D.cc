#include <iostream>

using ll = long long;

ll T;
ll n, x, y;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> x >> y;
		ll maxx = std::min(x-1, y)*2+1;
		std::cout << (n<=maxx?"YES\n":"NO\n");
	}
}