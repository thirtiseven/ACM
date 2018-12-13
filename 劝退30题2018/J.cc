#include <iostream>
 
int main(int argc, char *argv[]) {
	long long n;
	while(std::cin >> n) {
		bool ok = 1;
		long long x = 1;
		while (n > x) {
			x = x * 9;
			if (n <= x) {
				ok = 0;
			}
			x = x * 2;
		}
		if (!ok) {
			std::cout << "Stan wins." << std::endl;
		} else {
			std::cout << "Ollie wins." << std::endl;
		}
	}
}

