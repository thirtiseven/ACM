#include <iostream>

int n, t[55];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> t[i];
	}
	int d = 0, ans = 100;
	for (int i = 2; i < n; i++) {
		if (std::max(t[i-1], t[i+1]) < ans) {
			ans = std::max(t[i-1], t[i+1]);
			d = i;
		}
	}
	std::cout << d-1 << ' ' << ans << '\n';
}