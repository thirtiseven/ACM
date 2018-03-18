#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main(int argc, char *argv[]) {  
	double n[7], maxx = 0, inf[7];
	double q = 0;
	for (int i = 1; i <= 6; i++) {
		std::cin >> n[i];
		q += n[i]*double(i);
		maxx = std::max(n[i], maxx);
	}
	std::cout << std::fixed << std::setprecision(3  ) << std::abs((q-3.5)/maxx);
}