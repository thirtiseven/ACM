#include <iostream>

const int inf = 123456;

int T;
int d, x, s;
int c, pl, ps;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		int minps = inf, minpl = inf;
		int ans = 0, cur = 0;
		std::cin >> d >> x >> s;
		for (int i = 0; i < d; i++) {
			std::cin >> c >> pl >> ps;
			minps = std::min(minps, ps);
			minpl = std::min(minpl, pl);
			int t = 0;
			while (cur < c*s) {
				t ++;
				cur += 80;
			}
			cur -= c*s;
			ans += c * x * minpl + t * minps;
		}
		std::cout << ans << '\n';
	}
}