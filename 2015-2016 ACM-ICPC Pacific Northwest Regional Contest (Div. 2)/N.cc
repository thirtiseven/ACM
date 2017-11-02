#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::string s;
	int n, k, ip;
	std::cin >> n >> k;
	int ans1 = 1, ans2 = k;
	for(int i = 0; i < n; i++) {
		std::cin >> ip >> s;
		if(s[0] == 'S') {
			ans1 = std::max(ans1, ip);
		} else {
			ans2 = std::min(ans2, ip);
		}
	}
	std::cout << ans1 + 1 << " " << ans2 - 1 << std::endl;
	return 0;
}