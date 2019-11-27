#include <iostream>
#include <cmath>

const double eps = 0.000001;

int main(int argc, char *argv[]) {  
	double V, N;
	std::cin >> V >> N;
	V *= N;
	double x = 0.1;
	for (int i = 1; i <= 9; i++) {
		std::cout << int(std::ceil(x*V*i)) << " \n"[i==9];
	}
}