#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

const int maxn = 123;

double p[maxn];

int main(int argc, char *argv[]) {  
	int T, n;
	std::string s;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		double pp;
		for (int i = 0; i < n; i++) {
			std::cin >> pp;
			p[i] = pp/100.0;
		}
		double ans = 0;
		if (s == "bit") {
			for (int i = 0; i < n; i++) {
				if (p[i] != 0) ans += p[i] * log2(p[i]);
			}
		} else if (s == "nat") {
			for (int i = 0; i < n; i++) {
				if (p[i] != 0) ans += p[i] * log(p[i]);
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (p[i] != 0) ans += p[i] * log10(p[i]);
			}
		}
		std::cout << std::fixed << std::setprecision(12) << -ans << '\n';
	}
}