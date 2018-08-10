#include <iostream>
#include <string>
#include <cstdio>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::string s;
	std::cin >> T;
	int a[300];
	int c[300];
	while (T--) {
		std::cin >> s;
		for (int i = 0; i < s.length(); i++) {
			a[i] = (s[i] - '0');
		} 
		int ans = s.length()-1;
		while (ans--) {
			bool yes = 0;
			std::fill(c, c+300, 0);
			for (int f = 0; f < 10; f++) {
				c[0] = (10+f-a[0])%10;
				c[ans] -= c[0];
				for (int i = 1; i+ans < s.length(); i++) {
					c[i] += c[i-1];
					int t = (10+f-(a[i]+c[i])%10)%10;
					c[i] += t;
					c[i+ans] -= t;
				}
				for (int i = 0; i <= s.length(); i++) {
					std::cout << c[i] << " ";
				}
				std::cout << '\n';
				for (int i = 0; i < s.length(); i++) {
					if ((a[i] + c[i])%10 != f) {
						goto aa;
					}
				}
				yes = 1;
				aa:;
			}
			if (yes) {
				std::cout << ans << '\n';
				break;
			}
		}
	}
}