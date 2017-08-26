#include <iostream>
#include <cmath>
#include <iomanip>
#define pi acos(-1.0)

struct point {
	double x, y;
};

double dis(point a, point b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main(int argc, char *argv[]) {  
	int CAS;
	std::cin >> CAS;
	for(int i = 1; i <= CAS; i++) {
		point A, B, C;
		std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
		double m, l, t;
		m = dis(A, B);
		l = dis(B, C) / 2.0;
		t = sqrt(pow(m, 2) - pow(l, 2));
		double s = l * t;
		double r = 2 * s / (2 * m + 2 * l);
		double d = (l * l + r * r) / (2.0 * r);
		double alpha =  2 * asin(l/d);
		double ans = pi * d * 2 * (alpha/(2*pi)) + t;
		//std::cout << m << " " << l << " " << t << " " << s << " " << r << " " << d << " " << alpha/pi << " " << ans << std::endl;
		std::cout  << "Case #" << i << ": " << std::fixed << std::setprecision(4) << ans << std::endl;
	}
	return 0;
}