#include <iostream>
#include <string>
#include <vector>

std::string s;

int main(int argc, char *argv[]) {  
	std::cin >> s;
	int now;
	char cur;
	int l = 0, r = s.length()-1;
	int ans = 0;
	while (1) {
//		std::cout << l << ' ' << r << '\n';
		cur = s[l];
		if (cur != s[r]) {
			ans = 0;
			break;
		}
		while (s[l] == cur && l < s.length()) {
			l++;
			now++;
		}
		while (s[r] == cur && r >= 0) {
			r--;
			now++;
		}
		if (r < l) {
			if (now < 4) {
				ans = 0;
				break;
			} else {
				ans = now/2+1;
				break;
			}
		} else {
			if (now < 3) {
				ans = 0;
				break;
			}
		}
		now = 0;
	}
	std::cout << ans << '\n';
}