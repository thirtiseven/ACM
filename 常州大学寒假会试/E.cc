#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {  
	long double n, a0, an;
	int q;
	std::cin >> n >> a0 >> an >> q;
	for (int i = 0; i < q; i++) {
		long double l, r;
		std::cin >> l >> r;
		long double ans = a0+((an-a0)/n)*(l+r)/2.0*(r+1.0-l);
		std::cout << std::fixed << std::setprecision(0) << ans << std::endl;
	}
}