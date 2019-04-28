#include <iostream>

using ll = long long;

const int maxn = 130, maxm = 1234;
const int mod = 1e9+9;

ll dp[maxn][maxm], cnt[maxn][maxm];

int main(int argc, char *argv[]) {
	int k, b;
	std::cin >> k >> b;
	dp[0][0] = 1;
	cnt[0][0] = 0;
	for (int i = 1; i <= b; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][(j*2)%k] = (dp[i][(j*2)%k] + dp[i-1][j]) % mod;
			dp[i][(j*2+1)%k] = (dp[i][(j*2+1)%k] + dp[i-1][j]) % mod;
			cnt[i][(j*2)%k] = (cnt[i][(j*2)%k] + cnt[i-1][j]) % mod;
			cnt[i][(j*2+1)%k] = (cnt[i][(j*2+1)%k] + cnt[i-1][j] + dp[i-1][j]) % mod;
		}
	}
	std::cout << cnt[b][0];
}