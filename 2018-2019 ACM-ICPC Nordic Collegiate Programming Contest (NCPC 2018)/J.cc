#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int num0 = 0, num1 = 0;
	while (num0*(num0-1)/2 < a) {
		num0++;
	}
	while (num1*(num1-1)/2 < d) {
		num1++;
	}
	if (num0*(num0-1)/2 != a || num1*(num1-1)/2 != d) {
		std::cout << "impossible\n";
		exit(0);
	}
	if (b == 0 && c == 0) {
		if (a == 0) {
			num0 = 0;
		} else if (d == 0) {
			num1 = 0;
		}
	}
//	int x = num0 + num1;
//	if (x*(x-1)/2 != a+b+c+c) {
//		std::cout << "impossible\n";
//		exit(0);
//	}
	std::string ans = "";
//	std::cout << num0 << ' ' << num1<< '\n';
	while (num0 || num1) {
		if (b >= num1) {
			ans += "0";
			b -= num1;
			num0 --;
		} else {
			ans += "1";
			c -= num0;
			num1 --;
		}
//		std::cout << ans << '\n';
	}
	if (b || c) {
		std::cout << "impossible\n";
		exit(0);
	}
	std::cout << ans << "\n";
}