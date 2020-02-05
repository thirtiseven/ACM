#include <iostream>

using ll = unsigned long long;

int T;
ll x;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> x;
		ll d = 2;
		ll cnt = 0;
		while (x) {
			x /= d;
			cnt++;
			d++;
		}
		cnt--;
		std::cout << ((1LL<<cnt)-1) << '\n';
	}
}