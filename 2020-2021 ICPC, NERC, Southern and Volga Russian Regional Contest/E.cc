#include <iostream>
#include <algorithm>

int T, a[5];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		for (int i = 0; i < 4; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+4);
		std::cout << std::min(a[0], a[1]) * std::min(a[2], a[3]) << '\n';
	}
}