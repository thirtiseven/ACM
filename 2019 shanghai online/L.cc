#include <iostream>

int ans[1000007][12];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T, n, b;
	for (int i = 2; i <= 10; i++) {
		ans[0][i] = 0;
	}
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 2; j <= 10; j++) {
			int x = 0, temp = i;
			while (temp) {
				x += temp%j;
				temp /= j;
			}
			ans[i][j] = ans[i-1][j] + x;
		}
	}
	std::cin >> T;
	for (int i = 1; i <= T; i++) {
		std::cin >> n >> b;
		std::cout << "Case #" << i << ": " <<  ans[n][b] << '\n';
	}
}