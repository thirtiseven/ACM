#include <iostream>
#include <algorithm>
#include <cmath>

const int diff = 2;
int vis[100000 + 5];

int main(int argc, char *argv[]) {
	int n, k, r;
	std::cin >> n >> k >> r;
	for(int i = 0; i < k; i++) {
		int x;
		std::cin >> x;
		vis[x] = 1;
	}
	int num = 0, ans = 0;
	for(int i = 1; i <= r; i++) {
		num += vis[i];
	}
	ans += std::max(0, diff - num);
	for(int i = r; i >= 1; i --) {
		if(num == diff)  break;
		if(!vis[i]) vis[i] = 1, num++;
	}
	for(int nail = r + 1; nail <= n; nail++) {
		num = num - vis[nail - r] + vis[nail];
		if(num < diff)  vis[nail] = 1, ans++, num = diff;
	}
	std::cout << ans << '\n';
	return 0;
}