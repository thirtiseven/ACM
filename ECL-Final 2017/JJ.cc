#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
long long c[maxn], m[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		std::fill(m, m+maxn, 0);
		std::fill(c, c+maxn, 0);
		bool yes = 1;
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> c[i];
			m[i] = c[i] - c[i-1];
		}
		m[n+1] = -c[n];
		int zero = 1;
		for (int i = 1; i <= n+1; i++) {
			if (m[i] < 0) {
				for (int j = zero; j <= i-3; j++) {
					if (m[j] > 0) {
						if (m[j] >= (-m[i])) {
							m[j] += m[i];
							m[i] = 0;
							break;
						} else {
							m[i] += m[j];
							m[j] = 0;
							zero = j;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n+1; i++) {
			if (m[i] != 0) {
				yes = 0;
			}
		}
		std::cout << "Case #" << tt << ": " << (yes?"Yes\n":"No\n");	
	}
}