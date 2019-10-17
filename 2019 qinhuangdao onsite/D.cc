#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	int n;
	while (T--) {
		std::cin >> n;
		while (n % 5 == 0) {
			n /= 5;
		}
		while (n % 2 == 0) {
			n /= 2;
		}
		if (n == 1) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
		}
	}
}