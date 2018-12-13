#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1004;

int now[maxn];
std::vector<int> inp[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	std::fill(now, now+maxn, 0);
	int n, m;
	std::cin >> n >> m;
	int l, x;
	std::cin >> l;
	for (int i = 0; i < l; i++) {
		std::cin >> x;
		now[x] = 1;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> l;
		for (int j = 0; j < l; j++) {
			std::cin >> x;
			inp[i].push_back(x);
		}
	}
	bool yes = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt++;
		yes = 1;
		for (int j = 0; j < inp[i].size(); j++) {
			now[inp[i][j]]++;
		}
		for (int j = 1; j <= m; j++) {
			if (now[j] & 1) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << cnt << '\n';
			exit(0);
		}
	}
	for (int i = 0; i < n; i++) {
		cnt++;
		yes = 1;
		for (int j = 0; j < inp[i].size(); j++) {
			now[inp[i][j]]++;
		}
		for (int j = 1; j <= m; j++) {
			if (now[j] & 1) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << cnt << '\n';
			exit(0);
		}
	}
	std::cout << "-1\n";
}