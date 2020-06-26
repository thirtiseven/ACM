#include <iostream>
#include <string>

const int maxn = 9;

std::string s[maxn];
int num[maxn][maxn];
int T, n, m, cnt;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	int cas = 0;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
			for (int j = 0; j < m; j++) {
				num[i][j] = 0;
			}
		}
		cas++;
		cnt = 0;
		std::cout << "Image #" << cas << ": ";
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (s[i][j] == '#' && s[i][j-1] == '#' && s[i+1][j] == '#' && s[i][j+1] == '#' && s[i-1][j] == '#') {
					cnt++;
					num[i][j]++;
					num[i][j-1]++;
					num[i][j+1]++;
					num[i+1][j]++;
					num[i-1][j]++;
				}
			}
		}
//		std::cout << '\n';
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				std::cout << num[i][j] << ' ';
//			}
//			std::cout << '\n';
//		}
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (num[i][j] == 0 && s[i][j] == '#') {
					yes = 0;
				}
			}
		}
		if (yes == 0) {
			std::cout << "impossible\n\n";
			continue;
		}
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (num[i][j] > 1 && num[i-1][j] > 1 && num[i+1][j] > 1 && num[i][j+1] > 1 && num[i][j-1] > 1) {
					cnt--;
					num[i][j]--;
					num[i][j-1]--;
					num[i][j+1]--;
					num[i+1][j]--;
					num[i-1][j]--;
				}
			}
		}
		std::cout << cnt << "\n\n";
	}
}