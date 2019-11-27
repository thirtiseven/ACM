#include <iostream>
#include <cmath>
#include <iomanip>

const double eps = 1e-8;
const double pi = acos(-1.0);

int T;
double a, b, r, d;
double ans;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> r >> d;
		if (d >= 90 || b/(a+r) <= tan(d*pi/180.0)+eps) {
			ans = sqrt((a+r)*(a+r)+b*b)-r;
		} else {
			ans = cos(d*pi/180.0)*(a+r-r*cos(d*pi/180.0)+tan(d*pi/180.0)*(b-r*sin(d*pi/180.0)));
		}
		std::cout << std::fixed << std::setprecision(10) << ans << '\n';
	}
}