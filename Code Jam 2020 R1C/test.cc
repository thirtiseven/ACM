#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T; std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		std::cout << "Case #" << _ << ": " << '\n';
	}
}