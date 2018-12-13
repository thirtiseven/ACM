#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1e6+7;

int T, n, a[maxn], idx[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			idx[a[i]] = i;
		}
		std::set<std::pair<int, int>> l, r;
		for (int i = 1; i < n; i++) {
			if (i % 2 == 1) {
				l.insert(std::make_pair(std::min(idx[i], idx[i+1]), std::max(idx[i], idx[i+1])));
			} else {
				r.insert(std::make_pair(std::min(idx[i], idx[i+1]), std::max(idx[i], idx[i+1])));
			}
		}
		bool yes = 1;
		for (auto it: l) {
			auto x = l.lower_bound(std::make_pair(it.second, 0));
			x--;
			if (x->second > it.second) {
				yes = 0;
				break;
			}
		}
		for (auto it: r) {
			auto x = r.lower_bound(std::make_pair(it.second, 0));
			x--;
			if (x->second > it.second) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}