#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, s;
	int t, maxx = 0;
	std::cin >> n >> s;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		maxx = std::max(t, maxx);
	}
	int ans = (maxx*s)/1000+((maxx*s)%1000?1:0);
	std::cout << ans;
}