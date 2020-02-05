#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2e6+8;

int T, n, a, num[maxn];
std::vector<int> ca;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		ca.clear();
		std::cin >> n;
		std::fill(num, num+n+1, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			num[a]++;
		}
		for (int i = 1; i <= n; i++) {
			if (num[i] > 0) {
				ca.push_back(num[i]);
			}
		}
		std::sort(ca.begin(), ca.end());
		int ans = 0, ss = ca[0]+1, anss = 0;
		for (int i = ss; i >= 2; i--) {
			bool check = 1;
			for (auto it: ca) {
				if (it%(i-1) > it/(i-1)) {
					check = 0;
					break;
				}
			}
			if (check) {
				anss = i;
				break;
			}
		}
		for (auto it: ca) {
			ans += (it-1)/anss+1;
		}
		std::cout << ans << '\n';
	}
}