#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <tuple>

const int maxn = 1e5+7;
using ll = long long;
int flag[maxn], primes[maxn], totPrimes;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = 1;
			if (i % primes[j] == 0)
			break;
		}
	}
}

std::vector<std::tuple<ll, int, int>> ans;
 
int main(int argc, char *argv[]) {  
	euler_sieve(100000);
	ll l, r;
	std::cin >> l >> r;
	ll x;
	for (int i = 0; i < totPrimes; i++) {
		for (int j = i; j < totPrimes; j++) {
			x = 1LL*primes[i]*primes[j];
			if (x >= l && x <= r) {
				ans.push_back(std::make_tuple(x, primes[i], primes[j]));
			} else if (x > r) {
				break;
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << std::get<0>(it) << ' ' << std::get<1>(it) << ' ' << std::get<2>(it) << '\n';
	}
}