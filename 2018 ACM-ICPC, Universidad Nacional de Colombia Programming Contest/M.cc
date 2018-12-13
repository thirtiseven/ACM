#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {  
	long double n, m, k, ans = 0;
	std::cin >> n >> m >> k;
	if (m >= k-1) {
		ans = (k-1)/k + (m-k+1)/(k*(m+n-k+1));
	} else {
		ans = m/k;
	}
	std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
}