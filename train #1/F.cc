#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf = 1000005;
const int maxn = 105;

int T, n;
int a[maxn], sum[maxn];
int dp[maxn][maxn];

int main()
{
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				dp[i][j] = inf;
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) {
				int j = i + len - 1;
				for (int k = 1; k <= j - i + 1; k++)
					dp[i][j] = min(dp[i][j], dp[i + 1][i + k - 1] + dp[i + k][j] + a[i] * (k - 1) + (sum[j] - sum[i + k - 1])*k);
			}
		}
		printf("Case #%d: %d\n", ca, dp[1][n]);
	}
	return 0;
}