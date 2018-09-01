#include <iostream>
#include <string>
#include <cstring>

const int maxn = 109;

char s[maxn][maxn], ans[maxn][maxn];
std::string mid;

int main(int argc, char *argv[]) {  
	int n, num = 0;
	while (std::cin >> n) {
		mid = "";
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		int x = 0, y = 0, op = n%2;
		while (x < n && y < n) {
			mid += s[x][y];
			if (y % 2 == 0 && x == 0 && y < n-1) {
				y++;
				continue;
			} else if (y == 0 && x%2 == 1 && x < n-1) {
				x++;
				continue;
			} else if (x == n-1 && (y%2==op)) {
				y++;
				continue;
			} else if (y == n-1 && (x%2==(1-op))) {
				x++;
				continue;
			} else if ((x+y)%2==1) {
				x++, y--;
				continue;
			} else if ((x+y)%2==0) {
				x--, y++;
			}
		}
		x = 0, y = 0;
		int cnt = 1;
		int vis[maxn][maxn];
		memset(vis, 0, sizeof(vis));
		vis[0][0] = 1;
		while(cnt<n*n) {
			while(y+1<n&&!vis[x][y+1])  vis[x][++y] = ++cnt;
			while(x+1<n&&!vis[x+1][y])  vis[++x][y] = ++cnt;
			while(x-1>=0&&!vis[x-1][y]) vis[--x][y] = ++cnt;
			while(y-1>=0&&!vis[x][y-1]) vis[x][--y] = ++cnt;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << mid[vis[i][j]-1];
			}
			std::cout << '\n';
		}
	}
}