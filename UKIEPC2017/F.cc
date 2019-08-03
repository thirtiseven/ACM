#include <iostream>
#include <iomanip>

const int maxn = 432;

int main(int argc, char *argv[]) {  
	double dp[maxn][maxn];
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++){
			if (j != 0) {
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) * 0.5;
			}
			if (j < n) {
				dp[i][j] = std::max(dp[i][j], (dp[i-1][j] + dp[i-1][j+1]) * 0.5);
			}
		}
	}
	std::cout << std::fixed << std::setprecision(7) << dp[k][0] << '\n';
}