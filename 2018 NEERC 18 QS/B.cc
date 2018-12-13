#include <iostream>

const int maxn = 2e5+10;

int n, h, l[maxn], r[maxn], height[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> h;
	int ans = 0;
	height[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
		height[i] = height[i-1] + l[i] - r[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int x = std::lower_bound(height+i+1, height+n+1, h+height[i]) - height - 1;
		ans = std::max(ans, r[x]-l[i]+(h-height[x]+height[i]));
	}
	std::cout << ans << '\n';
}