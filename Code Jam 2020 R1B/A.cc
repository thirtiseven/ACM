#include <iostream>
#include <string>

using ll = long long;

ll T, x, y;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		std::cin >> x >> y;
		ll temp = std::abs(x)+std::abs(y), cnt = 0, cur = 1;
		while (temp) {
			cnt++;
			temp/=2;
			cur *= 2;
		}
		cur /= 2;
		std::string ans = "";
		for (int i = 0; i < cnt; i++) {
			ans += "?";
		}
//		std::cout << ans << '\n';
		for (int i = cnt-1; i >= 0; i--) {
			if (std::abs(x) > std::abs(y)) {
				if (x > 0) {
					ans[i] = 'E';
					x -= cur;
				} else {
					ans[i] = 'W';
					x += cur;
				}
			} else {
				if (y > 0) {
					ans[i] = 'N';
					y -= cur;
				} else {
					ans[i] = 'S';
					y += cur;
				}
			}
			cur /= 2;
		}
		if (x == 0 && y == 0) {
			std::cout << "Case #" << _ << ": " << ans << '\n';
		} else {
			std::cout << "Case #" << _ << ": " << "IMPOSSIBLE" << '\n';
		}
	}
}