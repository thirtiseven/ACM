#include <iostream>
#include <set>

const int maxn = 123;
int t, n, k, r, c, a[maxn][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CAS = 1; CAS <= t; CAS++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> a[i][j];
			}
		}
		k = r = c = 0;
		for (int i = 0; i < n; i++) {
			k += a[i][i];
		}
		for (int i = 0; i < n; i++) {
			std::set<int> x;
			for (int j = 0; j < n; j++) {
				x.insert(a[i][j]);
			}
			if (x.size() < n) {
				r++;
			}
		}
		for (int i = 0; i < n; i++) {
			std::set<int> x;
			for (int j = 0; j < n; j++) {
				x.insert(a[j][i]);
			}
			if (x.size() < n) {
				c++;
			}
		}
		std::cout << "Case #" << CAS << ": " << k << ' ' << r << ' ' << c << '\n';
	}
}