#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long a[40], n;
	long long ans = 1;
	long long aa;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	std::reverse(a, a+n);
	aa = 1;
	for(int i = 0; i < n; i++) {
		aa *= a[i];
		ans += aa;
	}
	std::cout << ans << std::endl;
	return 0;
}