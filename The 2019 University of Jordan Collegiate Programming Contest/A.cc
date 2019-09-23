#include <iostream>

int main(int argc, char *argv[]) {  
	int x, y;
	std::cin >> x >> y;
	if (x >= y) {
		std::cout << "1\n";
	} else {
		std::cout << "0\n";
	}
}