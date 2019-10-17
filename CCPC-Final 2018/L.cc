#include <iostream>
#include <cstring>

using ll = long long;

const int maxn = 1e7+7;

ll flag[maxn], primes[maxn], totPrimes;

void euler_sieve(ll n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (ll i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (ll j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
			break;
		}
	}
}

bool _isPrime(ll key) {
	for (ll i = 2; i * i <= key; ++i) {
		if (key % i == 0) return false;
	}
	return true;
}

ll prime[6] = {2, 3, 5, 233, 331};
ll qmul(ll x, ll y, ll mod) { // 乘法防止溢出， 如果p * p不爆ll的话可以直接乘； O(1)乘法或者转化成二进制加法
 
 
	return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
}

ll qpow(ll a, ll n, ll mod) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = qmul(ret, a, mod);
		a = qmul(a, a, mod);
		n >>= 1;
	}
	return ret;
}
bool Miller_Rabin(ll p) {
	if(p < 2) return 0;
	if(p != 2 && p % 2 == 0) return 0;
	ll s = p - 1;
	while(! (s & 1)) s >>= 1;
	for(int i = 0; i < 5; ++i) {
		if(p == prime[i]) return 1;
		ll t = s, m = qpow(prime[i], s, p);
		while(t != p - 1 && m != 1 && m != p - 1) {
			m = qmul(m, m, p);
			t <<= 1;
		}
		if(m != p - 1 && !(t & 1)) return 0;
	}
	return 1;
}

int T;
ll x;

int main(int argc, char *argv[]) {  
	euler_sieve(10000000);
	std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		std::cin >> x;
		if (x <= 11) {
			std::cout << "Case " << _ << ": " << "IMPOSSIBLE" << '\n';
		} else {
			bool odd = 0;
			if (x % 2 == 0) {
				x -= 8;
			} else {
				odd = 1;
				x -= 9;
			}
			ll ans1 = 0, ans2 = 0;
			if (x == 4) {
				ans1 = 2, ans2 = 2;
			} else {
				for (ll i = 1; i < totPrimes; i++) {
//					std::cout << x-primes[i] << ' ' << primes[i] << '\n';
					if (Miller_Rabin(x-primes[i])) {
						ans1 = primes[i], ans2 = x-primes[i];
						break;
					}
				}
			}
			if (odd) {
				std::cout << "Case " << _ << ": " << "2 2 2 3 " << ans1 << ' ' << ans2 << '\n';
			} else {
				std::cout << "Case " << _ << ": " << "2 2 2 2 " << ans1 << ' ' << ans2 << '\n';
			}
		}
	}
}