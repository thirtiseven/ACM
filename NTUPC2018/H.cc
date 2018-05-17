#include <iostream>
#include <cstring>

const int maxn = 55;
int minecraft[maxn][maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while(T--) {
		memset(minecraft, 0, sizeof(minecraft));
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> minecraft[i][j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (minecraft[i][j]) {
					ans++;
					if (minecraft[i][j] > minecraft[i-1][j]) {
						ans += (minecraft[i][j] - minecraft[i-1][j]);
					}
					if (minecraft[i][j] > minecraft[i+1][j]) {
						ans += (minecraft[i][j] - minecraft[i+1][j]);
					}
					if (minecraft[i][j] > minecraft[i][j-1]) {
						ans += (minecraft[i][j] - minecraft[i][j-1]);
					}
					if (minecraft[i][j] > minecraft[i][j+1]) {
						ans += (minecraft[i][j] - minecraft[i][j+1]);
					}
				}
			}
		}
		std::cout << ans << '\n';
	}
}