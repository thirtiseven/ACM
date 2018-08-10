#include <iostream>
#include <set>
#include <algorithm>

const int maxn = 100008;
using ll = long long;
ll a[maxn], num[maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		ll n, k;
		std::cin >> n >> k;
		std::fill(num, num+maxn, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			num[a[i]]++;
		}
		std::sort(a+1, a+n+1);
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) continue;
			if (k%a[i] == 0) {
				if (k == a[i]*a[i] && num[a[i]] >= 2) {
					std::cout << a[i] << " " << a[i] << '\n';
					goto outt;
				} else if (num[k/a[i]] && k != a[i]*a[i]) {
					std::cout << a[i] << " " << k/a[i] << '\n';
					goto outt;
				}
			}
		}
		std::cout << "-1\n";
		outt:;
	}
}