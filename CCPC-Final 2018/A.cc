#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int n, m, T;
std::pair<int, int> p[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	int cas = 0;
	while (T--) {
		cas++;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i].first;
		}
		for (int i = 0; i < n; i++) {
			std::cin >> p[i].second;
		}
		std::sort(p, p+n);
		int curtime = 0, curpro = 0;
		for (int i = 0; i < n; i++) {
			curtime += p[i].second;
			if (curtime <= m) {
				curpro++;
			} else {
				break;
			}
		}
		std::cout << "Case " << cas << ": " << curpro << '\n';
	}
}