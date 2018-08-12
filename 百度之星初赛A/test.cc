#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int k;
	while (std::cin >> k) {
		int i = floor((sqrt(1+8*(k-1))-1)/2);
		int j = k-i*(i+1)/2-1;
		std::cout << k << " " << i << " " << j << '\n';
	}
}