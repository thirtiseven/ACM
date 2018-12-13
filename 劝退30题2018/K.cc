#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m;
	while (std::cin >> n >> m) {
		if (!n && !m) exit(0);
		if (n%2&&m%2) {
			std::cout << "What a pity!\n";
		} else {
			std::cout << "Wonderful!\n";
		}
	}
}