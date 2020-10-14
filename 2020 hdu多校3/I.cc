#include <iostream>
#include <algorithm>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int l = 0, r = 0;
		int cur = 0, star = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				cur++;
			} else if (s[i] == ')') {
				cur--;
			} else {
				star++;
			}
			if (cur < 0) {
				l = std::min(l, cur);
			}
		}
		l = 0 - l;
		r = cur+l+r;
//		std::cout << l << ' ' << r << '\n';
		if (l + r > star) {
			std::cout << "No solution!\n";
			continue;
		}
		int x = l, y = star-r;
		cur = 0;
		std::string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '*') {
				if (cur < x) {
					ans += "(";
				} else if (cur < y) {
					;
				} else {
					ans += ")";
				}
				cur++;
			} else {
				ans += s[i];
			}
		}
//		std::cout << ans << '\n';
		cur = 0;
		bool yes = 1;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] == '(') {
				cur++;
			} else {
				cur--;
			}
			if (cur < 0) {
				yes = 0;
			}
		}
		if (cur != 0) {
			yes = 0;
		}
		if (yes) {
			std::cout << ans << '\n';
		} else {
			std::cout << "No solution!\n";
		}
	}
}