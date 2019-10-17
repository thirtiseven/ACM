#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long;

const int maxn = 2567;
const ll mod = 1000000007;
ll n, k, temp;

ll dp[maxn][maxn];

ll gao(ll a, ll b) {
	if (dp[a][b] != 0) {
		return dp[a][b];
	}
	if (a < b) {
		return 0;
	}
	if (b == 2) {
		return 2;
	}
	ll res = (b * gao(a-1, b-1) + (b-1) * gao(a-1, b)) % mod;
	dp[a][b] = res;
//	std::cout << a << ' ' << b << ' ' << res << '\n';
	return res;
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	memset(dp, 0, sizeof(dp));
	std::cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		std::cin >> temp;
	}
	std::cout << gao(n, k) << '\n';
}