#include <iostream>
#include <set>
#include <queue>

const int maxn = 3e5+7;
long long x[maxn];
int n;

int check(int v) {
	long long add = 0, mis = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] < v) {
			add += (v-x[i]);
		} else if (x[i] > v) {
			mis += ((x[i]-v)/2);
		}
	}
	if (add > mis) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> x[i];
		}
		int l = 0, r = 100000000, mid;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		std::cout << l-1 << '\n';
	}
}