#include <iostream>
#include <cmath>
#include <algorithm>

const int maxn=5e6+7;
using ll = long long;

ll mu[maxn];
void getMu() {
	for(ll i=1; i<=maxn; i++) {
		ll target=i==1?1:0;
		ll delta=target-mu[i];
		mu[i] = delta;
		for(ll j=i+i;j<=maxn;j+=i) {
			mu[j]+=delta;
		}
	}
}

int main(int argc, char *argv[]) {  
	getMu();
	ll n, m, k;
	while (std::cin >> n >> m >> k) {
		n--, m--;
		if (n==0 && m==0) {
			std::cout << "true\n";
		} else if (n==0||m==0) {
			if (1LL == k) {
				std::cout << "false\n";
			} else {
				std::cout << "true\n";
			}
		} else {
			long long ans = 2;
			for (ll g = 1; g <= std::min(n, m); g++) {
				ans += floor(m/g)*floor(n/g)*mu[g];
			}
			if (ans >= k) {
				std::cout << "false\n";
			} else {
				std::cout << "true\n";
			}
		}
	}
}