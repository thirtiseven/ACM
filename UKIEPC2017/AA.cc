#include <iostream>

const int maxn = 21;

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int h[maxn], r[maxn], t[maxn], maxx = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> h[i] >> r[i] >> t[i];
		maxx = std::max(h[i], maxx);
	}
	bool yes = 0;
	int now = 0;
	int upper = maxx * 1825;
	while (now <= upper) {
		bool check = 1;
		for (int i = 0; i < n; i++) {
			int cur = now % h[i];
			if (r[i] < t[i]) {
				if (cur > r[i] && cur < t[i]) {
					check = 0;
					break;
				}
			} else {
				if (cur > r[i] || cur < t[i]) {
					check = 0;
					break;
				}
			}
		}
		if (check) {
			std::cout << now << '\n';
			exit(0);
		}
		now++;
	}
	std::cout << "impossible\n";
}