#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 123;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CC = 1; CC <= T; CC++) {
		int n;
		long double a[maxn];
		long double aa, bb;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%Lf:%Lf", &aa, &bb);
			a[i] = aa/(aa+bb);		
		}
		std::sort(a, a+n);
		long double ans = 0;
		int cnt = 0;
		for (;cnt < n; cnt++) {
			ans += a[cnt];
			cnt++;
			if (ans >= 1-1e-51) {
				break;
			}
		}
		std::cout << "Case #" << CC << ": " << cnt-1 << '\n';
	}
}