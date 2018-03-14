#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	long long n, k;
	std::cin >> n >> k;
	if (n == k) {
		std::cout << 2;
	} else if ((n-1)%k == 0) {
		std::cout << (n-1)/k*2;
	} else if ((n-1)%k == 1) {
		std::cout << (n-1)/k*2+1;
	} else {
		std::cout << (n-1)/k*2+2;
	}
}