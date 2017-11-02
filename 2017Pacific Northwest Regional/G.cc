#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n, m;
	std::string g[55];
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> g[i];
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == 'o') {
				int down = 1;
				while(i + down < n && g[i+down][j] == '.') {
					down++;
				}
				g[i][j] = '.';
				g[i+down-1][j] = 'o';
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << g[i] << "\n";
	}
	return 0;
}