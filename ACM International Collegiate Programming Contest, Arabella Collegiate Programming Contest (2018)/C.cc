#include <iostream>
#include <iomanip>
#include <cmath>

int T;
long double a, b, c, x;

long double dis(long double a, long double b) {
	return std::sqrt(a*a+b*b);
}

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c >> x;
		long double ans = 0.0;
		long double xx = b*x/100.0, yy = a*x/100.0;
		ans += dis(b+c+c+b-xx, a-yy);
		ans += dis(xx, yy);
		ans += dis(a, b+c+c);
		std::cout << std::fixed << std::setprecision(12) << ans << '\n';
	}
}