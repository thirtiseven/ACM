#include <iostream>
#include <algorithm>

int T, x;
char c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	int ans = 0;
	while (T--) {
		std::cin >> c >> x;
		if (c == 'S') {
			ans = std::max(ans, x);
		} else {
			int y = 1;
			for (int i = 0; i < x; i++) {
				y *= 2;
			}
			ans = std::max(ans, y-1);
		}
	}
	std::cout << ans << '\n';
}