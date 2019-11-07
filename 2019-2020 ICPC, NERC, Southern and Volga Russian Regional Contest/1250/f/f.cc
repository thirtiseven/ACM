#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int ans = 100000000;
	for (int i = 1; i <= n; i++) {
		if (n%i==0) {
			ans = std::min(ans, n/i*2+i*2);
		}
	}
	std::cout << ans << '\n';
}