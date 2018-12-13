#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 123;

int d[maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n, r, R, x, y;
		std::cin >> n >> R >> r;
		int minn = 1e9+7;
		for (int i = 0; i < n; i++) {
			std::cin >> x >> y;
			d[i] = x*x+y*y;
			minn = std::min(d[i], minn);
		}
		std::vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (d[i] <= (2*r-R)*(2*r-R)) {
				ans.push_back(i);
			}
		}
		if (ans.size() == 0) {
			for (int i = 0; i < n; i++) {
				if (d[i] == minn) {
					ans.push_back(i);
				}
			}
		}
		std::cout << ans.size() << "\n" << ans[0]+1;
		for (int i = 1; i < ans.size(); i++) {
			std::cout << " " << ans[i]+1;
		}
		std::cout << '\n';
	}
}