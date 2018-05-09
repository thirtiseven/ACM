#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n, m, a, b;
	std::string ss[12];
	while (std::cin >> n >> m >> a >> b) {
		for (int i = 0; i < n; i++) {
			std::cin >> ss[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a; j++) {
				for (int k = 0; k < m; k++) {
					for (int h = 0; h < b; h++) {
						std::cout << ss[i][k];
					}
				}
				std::cout << '\n';
			}
		}
	}
}