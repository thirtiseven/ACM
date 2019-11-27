#include <iostream>
#include <string>
#include <random>

const int maxn = 500+7;
int d[maxn][maxn], ans[maxn][maxn];
int n, seed;
std::string s;

int main(int argc, char *argv[]) { 
	std::cin >> n; 
	for(int i = 1; i <= n; i++) {
		std::cin >> s;
		for(int j = 1; j <= n; j++) {
			d[i][j] = int(s[j-1]-'0');
			ans[i][j] = 0;
		}
	}
	for(int i = n-1; i >= 1; i--) {
		for(int j = i; j <= n; j++) {
			int tot = 0;
			for(int k = i+1; k < j; k++) {
				tot += d[i][k] * d[k][j];	
			}
			tot %= 10;
			if (tot != d[i][j]) {
				ans[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << ans[i][j];
		}
		std::cout << '\n';
	}
}