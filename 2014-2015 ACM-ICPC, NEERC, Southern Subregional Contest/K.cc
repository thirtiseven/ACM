#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
int T, n;
int vis[maxn];
int mp[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		memset(vis, 0, sizeof(vis));
		//cin >> n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				//cin >> mp[i][j];
				scanf("%d", &mp[i][j]);
		for (int i = n; i > 1; i--) {
			int val = mp[1][i], j = 2;
			while (vis[mp[val][j]]) j++;
			if (mp[val][j] == 1) {
				j = 2;
				while (mp[1][j] != val)
					printf("1 %d\n", mp[1][j++]);
					//cout << 1 << " " << mp[1][j++] << endl;
				//cout << 1 << " " << val << endl;
				printf("1 %d\n", val);
				break;
			}
			printf("%d %d\n", val, mp[val][j]);
			//cout << val << " " << mp[val][j] << endl;
			vis[val] = 1;
		}
		printf("\n");
		//cout << endl;
	}
	return 0;
}