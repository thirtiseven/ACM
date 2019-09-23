#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.14159265

int main(int argc, char *argv[]) {  
	long double v, s;
	std::cin >> v >> s;
	long double ans = (PI*s*s)/(4.0*sin(PI/v)*sin(PI/v));
	std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
}