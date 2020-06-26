#include <iostream>
#include <string>
#include <cassert>

using ll = long long;

ll T, A, B;
ll x;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T >> A >> B;
	x = A;
	ll limit = 1e9-x;
//	std::cout << limit << '\n';
	for (ll _ = 1; _ <= T; _++) {
		ll check[4];
		std::cout << "0 " << x << std::endl;
		std::cin >> s;
		if (s == "MISS") {
			check[0] = -1;
		} else {
			check[0] = 1;
		}
		std::cout << x << " " << "0" << std::endl;
		std::cin >> s;
		if (s == "MISS") {
			check[1] = -1;
		} else {
			check[1] = 1;
		}
		for (ll i = 0; i <= limit; i++) {
			for (ll j = 0; j <= limit; j++) {
				std::cout << (check[1])*i << ' ' << (check[0])*j << std::endl;
//				assert((check[1])*i <= 1000000000 && (check[1])*i >= -1000000000);
//				assert((check[0])*j <= 1000000000 && (check[0])*j >= -1000000000);
				std::cin >> s;
				if (s == "CENTER") {
					goto outside;
				} else if (s == "WRONG") {
					exit(0);
				}
			}
		}
		outside:;
	}
}