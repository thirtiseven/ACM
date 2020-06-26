#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 3.14159265358979;
int T;
double s, r;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		double ans = 0;
		std::cin >> s >> r;
		if (r*2 <= s) {
			ans = pi*r*r;
		} else if (s*s<=r*r*2) {
			ans = s*s;
		} else {
			double x = sqrt(r*r-s*s/4);
			double y = pi*r*r-r*r*atan(x/(s/2))*4;
			ans = y+x*s*2;
		}
		std::cout << std::fixed << std::setprecision(2) << ans << '\n';
	}
}