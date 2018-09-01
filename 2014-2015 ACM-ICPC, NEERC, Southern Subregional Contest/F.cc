#include <iostream>
#include <algorithm>

const int maxn = 2e5+9;

int main(int argc, char *argv[]) {  
	int n, k;
	int a[maxn], p[maxn], maxp[maxn], maxs[maxn];
	std::cin >> n >> k;
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		p[i] = p[i-1] + a[i];
	}
	if (n <= 2*k) {
		std::cout << p[n] << '\n';
		exit(0);
	}
	maxp[k-1] = 0;
	for (int i = k; i <= n-k; i++) {
		maxp[i] = std::max(maxp[i-1], p[i] - p[i-k]);
	}
	maxs[n-k+1] = 0;
	for (int i = n-k; i >= k; i--) {
		maxs[i] = std::max(maxs[i+1], p[i+k] - p[i]);
	}	
	int ans = 0;
	for (int i = k; i <= n-k; i++) {
		ans = std::max(ans, maxp[i] + maxs[i]);
	}
	std::cout << ans << '\n';
}