#include <iostream>

long long T, a, b, c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c;
		if (a <= b && a <= c) {
			std::cout << "First\n";
		} else if (b <= a && b <= c) {
			std::cout << "Second\n";
		} else {
			std::cout << "Third\n";
		}
	}
}