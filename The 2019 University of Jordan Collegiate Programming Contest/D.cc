#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int L, r, c, ans;
	std::cin >> L;
	while (L--) {
		std::cin >> r >> c;
		std::string res;
		ans = 0;
		if (r <= 7 || ((r == 8) && ((c != 6) && (c != 7))) || (c == 1 || c == 12)) {
			while (r > 3) {
				r--;
				res += "U";
				ans++;
			}
			while (r < 3) {
				r++;
				res += "D";
				ans++;
			}
			while (c < 3) {
				c++;
				res += "R";
				ans++;
			}
			while (c > 3) {
				c--;
				res += "L";
				ans++;
			}
		} else {
			if (c == 2) {
				c++;
				res += "R";
				ans++;
			} else if (c == 11) {
				c--;
				res += "L";
				ans++;
			}
			while (r > 10) {
				r--;
				res += "U";
				ans++;
			}
			while (r < 10) {
				r++;
				res += "D";
				ans++;
			}
			while (c < 3) {
				c++;
				res += "R";
				ans++;
			}
			while (c > 3) {
				c--;
				res += "L";
				ans++;
			}
		}
		std::cout << ans << '\n' << res << '\n';
	}
}