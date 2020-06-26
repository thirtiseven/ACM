#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n;
	std::cin >> n;
	if (n == 1) {
		std::cout << "1\n1\n";
	} else if (n == 2) {
		std::cout << "2\n0\n11\n";
	} else {
		std::cout << n-1 << '\n';
		for (int i = 2; i <= n; i++) {
			std::cout << '0';
			for (int j = 0; j < i-2; j++) {
				std::cout << '1';
			}
			std::cout << "0\n";
		}		
	}
}