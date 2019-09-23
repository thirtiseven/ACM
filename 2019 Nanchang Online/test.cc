#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	int n;
	while (T--) {
		std::cin >> n;
		std::cout << (n==1?"18000\n":"0\n");
	}
}