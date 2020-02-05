#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 105;

int n, m, a[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	int minn = 10000, idx = 10000, cnt = 0, sum = 0;
	std::vector<std::pair<int, int>> x;
	for (int i = 0; i < n-1; i++) {
		cnt = 0, sum = 0;
		x.clear();
		for (int j = 0; j < m; j++) {
			x.push_back(std::make_pair(a[j][n-1]-a[j][i], j));
			sum += (a[j][n-1]-a[j][i]);
		}
		std::sort(x.rbegin(), x.rend());
//		std::cout << sum << ':';
		while (sum > 0 && cnt < m) {
//			std::cout << x[cnt].first << ' ';
			sum -= x[cnt].first;
			cnt++;
		}
//		std::cerr << '\n';
		if (sum <= 0 && cnt < minn) {
			minn = cnt;
			idx = i;
		}
	}
	std::cout << minn << '\n';
	x.clear();
	cnt = 0, sum = 0;
	for (int j = 0; j < m; j++) {
		x.push_back(std::make_pair(a[j][n-1]-a[j][idx], j));
		sum += (a[j][n-1]-a[j][idx]);
	}
	std::sort(x.rbegin(), x.rend());
	while (sum > 0 && cnt < m) {
		sum -= x[cnt].first;
		std::cout << x[cnt].second+1 << ' ';
		cnt++;
	}
	std::cout << '\n';
}