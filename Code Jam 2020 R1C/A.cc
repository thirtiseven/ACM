#include <iostream>
#include <string>

std::string s;
int x, y;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T; std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		std::cin >> x >> y >> s;
		int ans = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'N') {
				y++;
			} else if (s[i] == 'E') {
				x++;
			} else if (s[i] == 'W') {
				x--;
			} else if (s[i] == 'S') {
				y--;
			}
			if (std::abs(x) + std::abs(y) <= i+1) {
				ans = i+1;
				break;
			}
		}
		std::cout << "Case #" << _ << ": ";
		if (ans == -1) {
			std::cout << "IMPOSSIBLE\n";
		} else {
			std::cout << ans << '\n';
		}
	}
}