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
				if (i+4<n) {
					int cnt = 0, ze = 0;
					for (int k = 0; k < 5; k++) {
						if (s[i+k][j] == c) cnt++;
						else if (s[i+k][j] == '0') ze++;
					}
					if (cnt==4&&ze==1) {
						yes = 1;
						goto end;
					}
				}
				if (j+4<n) {
					int cnt = 0, ze = 0;
					for (int k = 0; k < 5; k++) {
						if (s[i][j+k] == c) cnt++;
						else if (s[i][j+k] == '0') ze++;
					}
					if (cnt==4&&ze==1) {
						yes = 1;
						goto end;
					}
				}
				if (j+4<n&&i+4<n) {
					int cnt = 0, ze = 0;
					for (int k = 0; k < 5; k++) {
						if (s[i+k][j+k] == c) cnt++;
						else if (s[i+k][j+k] == '0') ze++;
					}
					if (cnt==4&&ze==1) {
						yes = 1;
						goto end;
					}
				}
				if (j-4<n&&i+4<n) {
					int cnt = 0, ze = 0;
					for (int k = 0; k < 5; k++) {
						if (s[i+k][j-k] == c) cnt++;
						else if (s[i+k][j-k] == '0') ze++;
					}
					if (cnt==4&&ze==1) {
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