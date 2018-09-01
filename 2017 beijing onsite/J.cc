/*
 * @Author: Simon 
 * @Date: 2018-08-20 13:30:43 
 * @Last Modified by: Simon
 * @Last Modified time: 2018-08-20 14:43:25
 */
#include <iostream>
#include <cstdio>
using namespace std;
typedef int Int;
#define int long long
#define INF 0x3f3f3f3f
#define maxn 105
int a[maxn];
int dp[maxn][maxn][maxn];
Int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,l,r;
	while(cin>>n>>l>>r)
	{
		memset(dp,INF,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			dp[i][i][1]=0;
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int x=l-1;x<r;x++)
		{
			for(int i=1;i+x<=n;i++)
			{
				int j=x+i;
				dp[i][j][x+1]=0;
				dp[i][j][1]=a[j]-a[i-1];
			}
		}
		for(int x=1;x<n;x++)
		{
			for(int i=1;i+x<=n;i++)
			{
				int j=x+i;
				for(int k=i;k<j;k++)
				{
					for(int c=2;c<=x+1;c++)
					{
						dp[i][j][c]=min(dp[i][j][c],dp[i][k][c-1]+dp[k+1][j][1]);
					}
				}
				for(int c=l;c<=r;c++)
						dp[i][j][1]=min(dp[i][j][1],dp[i][j][c]+a[j]-a[i-1]);
			}
		}
		if(dp[1][n][1]>=INF)
		{
			cout<<0<<endl;
		}
		else cout<<dp[1][n][1]<<endl;
	}
	cin.get(),cin.get();
	return 0;
}