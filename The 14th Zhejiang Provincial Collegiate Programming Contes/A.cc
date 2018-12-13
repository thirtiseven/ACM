#include <iostream>

int T, n, a, alice, bob;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> T;
	while (T--) {
		alice = bob = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			if (a == 1) {
				alice++;
			} else if (a == 2) {
				bob++;
			}
		}
		if (alice > bob) {
			std::cout << "Kobayashi\n";
		} else if (alice < bob) {
			std::cout << "Tohru\n";
		} else {
			std::cout << "Draw\n";
		}
	}
}