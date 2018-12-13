#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::string s;
		std::cin >> s;
		int numm = 0, numo = 0;
		for (auto it: s) {
			if (it == '*') numm++;
			else numo++;
		}
		int ans = 0;
		if (numm == 0) {
			std::cout << "0\n";
			continue;
		}
		if (numo <= numm) {
			std::string temp = "";
			for (int i = 0; i < (numm+1-numo); i++) {
				temp += "1";
			}
			s = temp + s;
			ans += numm+1-numo;
		}
//		std::cout << ans << " " << s << '\n';
		int len = s.length();
		std::stack<int> pos;
		for (int i = 0; i < len; i++) {
			if (s[i] != '*') {
				pos.push(i);
			}
		}
		numm = numo = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '*') {
				numm++;
				if (numo <= numm) {
					int pp = pos.top();
					pos.pop();
					std::swap(s[pp], s[i]);
					numo++, numm--;
					ans++;
//					std::cout << numo << " " << numm  << " " << ans << " " << s << '\n';
				}
			} else {
				numo++;
			}
		}
		if (s[len-1] != '*') {
			ans++;
		}
		std::cout << ans << '\n';
	}
}