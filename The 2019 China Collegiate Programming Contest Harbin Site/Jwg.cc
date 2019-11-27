#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 505;
int a[maxn][maxn];
int cnt[maxn][maxn];
int ans[maxn][maxn];
int vis[maxn];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			a[i][j + 1] = s[j] - '0';
	}
	for (int i = n - 1; i >= 1; i--) {
		ans[i][i + 1] = a[i][i + 1];
		cnt[i][i + 1] = a[i][i + 1];
		for (int j = i + 2; j <= n; j++) {
			//cout << "----------" << i << " " << j << endl;
			int t = 0;
			for (int k = i + 1; k < j; k++) vis[k] = 0;
			for (int k = i + 1; k < j; k++) {
				if (!vis[k] && cnt[i][k]) {
					vis[k] = 1;
					for (int u = k + 1; u < j; u++)
						if (cnt[k][u]) vis[u] = 1;
					t += cnt[k][j];
					//cout << cnt[k][j] << " " << k << " " << j << endl;
				}
			}
			//cout << i << " - " << j << " - " << t << endl;
			if (t % 10 == a[i][j]) {
				cnt[i][j] = t;
			}
			else {
				cnt[i][j] = t + 1;
				ans[i][j] = 1;
			}
		}
	}
	//cout << "-------------------\n";
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << cnt[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "-------------------\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j <= i) printf("0");
			else printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
