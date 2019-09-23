#include <iostream>
#include <algorithm>

using ll = long long;

const ll maxn = 2003, mod = 1e9+7;

ll dp[maxn][maxn];
ll n, k, m;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k >> m;
	ll ans = 0;
	for (int i = 0; i <= m; i++) {
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	int lower = std::min(m, k);
	for (int i = 1; i <= m; i++) {
		dp[i][0] = dp[i-1][1];
		for (int j = 1; j < lower; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			dp[i][j] %= mod;
		}	
		dp[i][lower] = dp[i-1][lower-1];
	}
	for (int i = 2; i <= m; i+=2) {
		ans += dp[i][0];
		ans %= mod;
	}
	ans = 2LL * n * ans;
	ans %= mod;
	std::cout << ans << '\n';
}