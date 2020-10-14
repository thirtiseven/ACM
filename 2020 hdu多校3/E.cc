#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;
using ll = long long;
const ll mod = 1e9+7;

static std::vector<ll> inverse_table(ll n, ll md) {
	std::vector<ll> inv(n);
	inv[1] = 1;
	for (ll i = 2; i < n; ++i) {
		inv[i] = (int64_t)(md - md / i) * inv[md % i] % md;
	}
	return inv;
}

struct Binomial {
	ll n, md;
	std::vector<ll> factorial, inv_factorial;
	Binomial(ll n, ll mod) : n(n), md(mod) {
		factorial.resize(n + 1);
		inv_factorial = inverse_table(n, md);
		factorial[0] = inv_factorial[0] = 1;
		for (ll i = 1; i <= n; i++) {
			factorial[i] = 1LL * factorial[i - 1] * i % md;
			inv_factorial[i] = 1LL * inv_factorial[i - 1] * inv_factorial[i] % md;
		}
	}
	ll choose(ll n, ll k) {
		if (k > n) return 0;
		return 1LL * factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] %
					 md;
	}
};


ll fa[maxn], T, n, u, v, a[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	Binomial C(100000, mod);
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		init(n);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			
		}
	}
}