#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n, maxx = 0;
		std::cin >> n;
		int a[123];
		for (int i= 0; i < n; i++) {
			std::cin >> a[i];
			maxx = std::max(a[i], maxx);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] + (100-maxx) >= 50) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}