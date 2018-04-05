#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main(int argc, char *argv[]) {  
	double k, p, x;
	std::cin >> k >> p >> x;
	int x1 = ceil(sqrt(k*p/x)), x2 = floor(sqrt(k*p/x));
	std::cout << std::fixed << std::setprecision(3) << std::min(double(x1)*x+(k*p)/double(x1), double(x2)*x+(k*p)/double(x2));
}