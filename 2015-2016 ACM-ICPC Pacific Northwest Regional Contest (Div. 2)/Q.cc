#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, ans = 1e7, a[100010];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for(int i = 0; i < n; i++) {
		ans = std::min(ans, a[i]+a[n-1-i]);
	}
	std::cout << ans;
	return 0;
}