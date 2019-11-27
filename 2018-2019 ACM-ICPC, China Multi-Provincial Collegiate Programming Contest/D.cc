#include <iostream>
#include <iomanip>

int main()
{
	int T;
	std::cin >> T;
	double n, m;
	for (int ca = 1; ca <= T; ca++) {
		std::cin >> n >> m;
		std::cout << "Case #"  << ca << ": " << std::fixed << std::setprecision(6) << (1/2.0) << ' ';
		std::cout << (m+1.0)/(m+m) << '\n';
	}
	return 0;
}