#include <iostream>
#include <string>
#include <algorithm>

int T, n;
std::string a, b;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		std::cin >> a >> b;
		std::string c = "", d = "";
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				c.push_back(a[i]);
				d.push_back(b[i]);
			}
		}
//		std::cout << c << ' ' << d << '\n';
		bool yes = 1;
		int x = c.length();
		for (int i = 0; i < x; i++) {
//			std::cout << d[i] << ' ' << c[(i+1)%x] << '\n';
			if (d[i] != c[(i+1)%x]) {
				yes = 0;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}