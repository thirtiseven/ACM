#include <iostream>

int main(int argc, char *argv[]) {  
	int T, V, E;
	std::cin >> T;
	while(T--) {
		std::cin >> V >> E;
		std::cout << E-V+2 << std::endl;
	}
}