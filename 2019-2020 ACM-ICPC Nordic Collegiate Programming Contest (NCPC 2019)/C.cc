#include <iostream>
#include <algorithm>

using ll = long long;

ll n, m, a;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> a;
	if (a % n == 0 || a % m == 0) {
		std::cout << "1\n";
	} else {
		bool yes = 0;
		if (n > m) {
			std::swap(n, m);
		}
		for (ll i = 1; i <= n; i++) {
			if (a%i == 0 && a/i < m) {
				yes = 1;
				break;
			}
		}
		if (!yes) {
			a = n*m-a;
			for (ll i = 1; i <= n; i++) {
				if (a%i == 0 && a/i < m) {
					yes = 1;
					break;
				}
			}
		}
		if (yes) {
			std::cout << "2\n";
		} else {
			std::cout << "3\n";
		}
	}
}