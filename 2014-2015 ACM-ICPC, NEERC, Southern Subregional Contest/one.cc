#include <iostream>
#include <algorithm>

const int maxn = 2009;

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a+1, a+n+1);
	int ans = 1, maxx = a[n], now = 0;
	for (;ans < n; ans++) {
		now += a[ans];
		if (now > maxx) {
			break;
		}
	}
	std::cout << ans << '\n';
}