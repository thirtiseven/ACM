#include <iostream>
#include <algorithm>

int T, n, ans = 1;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		if (n == 1) {
			std::cout << 26 << '\n';
		} else if (n == 2) {
			std::cout << 676 << '\n';
		} else if (n == 3) {
			std::cout << 17576 << '\n';
		} else {
			std::cout << 26*25*24 << '\n';
		}
	}
}