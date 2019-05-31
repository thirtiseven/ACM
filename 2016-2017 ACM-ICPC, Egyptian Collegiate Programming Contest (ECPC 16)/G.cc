#include <iostream>
#include <algorithm>
#include <cstring>

const int mod = 1e9+7;
const int maxn = 1e3+3;
using ll = long long;

int main(int argc, char *argv[]) { 
	std::freopen("galactic.in", "r", stdin); 
	int T;
	std::cin >> T;
	while (T--) {
		ll n, k;
		std::cin >> n >> k;
		ll dp[maxn][maxn];
		memset(dp, 0, sizeof(dp));
		if (n < k) {
			std::cout << "0\n";
			continue;
		}
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][1] = 1;
			for (int j = 1; j <= i; j++) {
				dp[i][j] = j*dp[i-1][j]%mod + j*dp[i-1][j-1]%mod;
				dp[i][j] %= mod;
			}
		}
		std::cout << dp[n][k] << '\n';
	}
}