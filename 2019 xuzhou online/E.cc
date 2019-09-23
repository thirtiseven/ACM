#include <iostream>
#include <map>
#include <algorithm>

const int maxn = 5e5+7;

std::map<int, int> mp;
int n, m;
int x[maxn], w[maxn];

int main(int argc, char *argv[]) {  
	int cnt = 0;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	int maxx = 0;
	for (int i = n-1; i >= 0; i--) {
		if (w[i] > maxx) {
			maxx = w[i];
			mp[maxx-m] = i;
			x[cnt] = maxx-m;
			cnt++;
		}
	}
	std::sort(x, x+cnt);
	int tmp = mp[x[std::lower_bound(x, x+cnt, w[0]) - x]];
	if (tmp <= 0) {
		std::cout << "-1";
	} else {
		std::cout << tmp-1;
	}
	for (int i = 1; i < n; i++) {
		tmp = mp[x[std::lower_bound(x, x+cnt, w[i]) - x]];
//		std::cerr << tmp << ' ';
		if (tmp <= i) {
			std::cout << " -1";
		} else {
			std::cout << ' ' << tmp-i-1;
		}
	}
}