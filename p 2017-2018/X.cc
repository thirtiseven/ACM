#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::cout << n << ":\n";
	for (int i = 2; i <= (n+1)/2; i++) {
		if (n%(i+i-1) == 0 || (n-(i))%(i+i-1) == 0) {
			std::cout << i << ',' << i-1 << '\n';
		}
		if (n%i==0) {
			std::cout << i << ',' << i << '\n';
		}
	}
}