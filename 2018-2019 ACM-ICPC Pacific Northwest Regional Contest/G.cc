#include <iostream>
#include <cmath>
#include <iomanip>

double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(int argc, char *argv[]) {  
	double x, y, x1, x2, y1, y2;
	std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	double ans = 10000;
	ans = std::min(ans, dis(x, y, x1, y1));
	ans = std::min(ans, dis(x, y, x1, y2));
	ans = std::min(ans, dis(x, y, x2, y1));
	ans = std::min(ans, dis(x, y, x2, y2));
	if (x < std::max(x1, x2) && x > std::min(x1, x2)) {
		ans = std::min(ans, std::abs(y-y1));
		ans = std::min(ans, std::abs(y-y2));
	}
	if (y < std::max(y1, y2) && y > std::min(y1, y2)) {
		ans = std::min(ans, std::abs(x-x1));
		ans = std::min(ans, std::abs(x-x2));
	}
	std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
}