#include <iostream>
#include <cstring>
#include <iomanip>

const int maxn = 53;

double dp[maxn][maxn][maxn*maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1.0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k <= n*m; k++) {
					int area = n*m-k+1;
					dp[i][j][k] = ((double)((n-i+1)*(m-j+1))/(double)(area)) * dp[i-1][j-1][k-1];
					dp[i][j][k] += ((double)((n-i+1)*(j))/(double)(area)) * dp[i-1][j][k-1];
					dp[i][j][k] += ((double)((i)*(m-j+1))/(double)(area)) * dp[i][j-1][k-1];
					dp[i][j][k] += ((double)((i)*(j)-k+1)/(double)(area)) * dp[i][j][k-1];
//					std::cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
				}
			}
		}
		double ans = 0;
		for (int i = 1; i <= n*m; i++) {
			ans += ((dp[n][m][i])-(dp[n][m][i-1]))*i;
		}
		std::cout << std::fixed << std::setprecision(12) << ans << '\n';
	}
}