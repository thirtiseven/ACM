#include <iostream>
#include <string>

std::string s[22];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		char c;
		std::cin >> n >> c;
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		bool yes = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == c) {
					if (i+4<n && s[i+1][j] == c && s[i+2][j] == c && s[i+3][j] == c && s[i+4][j] == '0') {
						yes = 1;
						goto end;
					}
					if (j+4<n && s[i][j+1] == c && s[i][j+2] == c && s[i][j+3] == c && s[i][j+4] == '0') {
						yes = 1;
						goto end;
					}
					if (j+4<n && i+4<n && s[i+1][j+1] == c && s[i+2][j+2] == c && s[i+3][j+3] == c && s[i+4][j+4] == '0') {
						yes = 1;
						goto end;
					}
					if (j+4<n && i-4>=0 && s[i-1][j+1] == c && s[i-2][j+2] == c && s[i-3][j+3] == c && s[i-4][j+4] == '0') {
						yes = 1;
						goto end;
					}
					if (j-4>=0 && i-4>=0 && s[i-1][j-1] == c && s[i-2][j-2] == c && s[i-3][j-3] == c && s[i-4][j-4] == '0') {
						yes = 1;
						goto end;
					}
					if (j-4>=0 && i+4<n && s[i+1][j-1] == c && s[i+2][j-2] == c && s[i+3][j-3] == c && s[i+4][j-4] == '0') {
						yes = 1;
						goto end;
					}
					if (i-4>=0 && s[i-1][j] == c && s[i-2][j] == c && s[i-3][j] == c && s[i-4][j] == '0') {
						yes = 1;
						goto end;
					}
					if (j-4>=0 && s[i][j-1] == c && s[i][j-2] == c && s[i][j-3] == c && s[i][j-4] == '0') {
						yes = 1;
						goto end;
					}
				}
			}
		}
		end:;
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}