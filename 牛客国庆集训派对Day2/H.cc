#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {  
	double n, m, k;
	int T;
	std::cin >> T;
	int cnt = 0;
	while (T--) {
		cnt++;
		double ans = 0;
		std::cin >> n >> m >> k;
		while(k--) {
			ans += n/m; 
			n--, m--;
		}
		std::cout << std::fixed << std::setprecision(12) << "Case #" << cnt << ": " << ans << std::endl;
	}
}