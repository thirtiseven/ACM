#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		if (n == 1) {
			std::cout << 5 << '\n';
		} else {
			std::cout << n+5 << '\n';
		}
	}
}