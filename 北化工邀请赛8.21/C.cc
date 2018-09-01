#include <iostream>
#include <cmath>

bool is_prime(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {  
	int n, T;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		if (is_prime(n)) {
			std::cout << "1\n";
		} else if (n%2==0 || is_prime(n-2)) {
			std::cout << "2\n";
		} else {
			std::cout << "3\n";
		}
	}
}