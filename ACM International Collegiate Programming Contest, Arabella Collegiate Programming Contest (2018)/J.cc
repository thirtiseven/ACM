#include <iostream>
long long T, n;
int main() {
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::cout << n + 1 - (1LL<<__builtin_popcountll(n)) << '\n';
	}
}