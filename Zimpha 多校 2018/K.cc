#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	int a, b;
	std::string s;
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> s;
		int h, m;
		double timezone = std::stod(s.substr(4));
//		std::cout << timezone << '\n';
		h = int(timezone);
		m = int((timezone - double(floor(timezone)))*60.0+0.5);
//		std::cout << h << " " << m << '\n';
		if (s[3] == '-') {
			h = 23-h;
			m = 60-m;
			if (m == 60) {
				h++;
				m = 0;
			}
			h%=24;
		}
//		std::cout << h << " " << m << '\n';
	 	h = a+24-8+h+(b+m)/60;
		m = (b+m)%60;
		h %= 24;
		if (h < 10) std::cout << "0";
		std::cout << h << ":" << (m < 10?"0":"") << m << '\n';
	}
}