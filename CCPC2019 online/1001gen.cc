#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b, c;
	while (std::cin >> a >> b >> c) {
		std::cout << ((a^c)&(b^c)) << '\n';
	}
}