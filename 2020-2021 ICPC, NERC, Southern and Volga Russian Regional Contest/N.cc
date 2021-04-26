#include <iostream>
#include <algorithm>

int T, a1, a2, a3, c1, c2, c3, c4, c5;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a1 >> a2 >> a3 >> c1 >> c2 >> c3 >> c4 >> c5;
		bool yes = 1;
		a1 -= c1;
		a2 -= c2;
		a3 -= c3;
		if (a1 >= 0) {
			int tem = std::min(a1, c4);
			c4 -= tem;
			a1 -= tem;
		} else {
			std::cout << "NO\n";
			continue;
		}
		if (a2 >= 0) {
			int tem = std::min(a2, c5);
			c5 -= tem;
			a2 -= tem;
		} else {
			std::cout << "NO\n";
			continue;
		}
		a3 -= c4;
		a3 -= c5;
		if (a3 < 0) {
			std::cout << "NO\n";
			continue;
		}
		std::cout << "YES\n";
	}
}