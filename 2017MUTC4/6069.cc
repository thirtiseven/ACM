#include <iostream>

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		int odd = 0, even = 0, t;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> t;
			if (t%2==0) {
				even++;
			} else {
				odd++;
			}
		}
		std::cout << "2 " << (odd >= even?1:0) << '\n';
	}
}