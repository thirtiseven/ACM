#include <bits/stdc++.h>
using namespace std;
int a[55];
int dp[55][2];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <=n; i++)
	{
		scanf("%d", &a[i]);
	}
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j])
				dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			else if(a[i] < a[j])
				dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}

	}
	printf("%d\n", max(dp[n][0], dp[n][1]));
	return 0;
}