#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T, V, aa[1009];
	std::cin >> T;
	while (T--) {
		std::cin >> V;
		int temp;
		memset(aa, 0, sizeof(aa));
		for (int i = 0; i < V; i++) {
			std::cin >> temp;
			aa[temp]++;
		}
		int ans = 0;
		for (int i = 0; i <= 1000; i++) {
			if (aa[ans] < aa[i]) {
//				std::cout << aa[ans] << " " << aa[i] << '\n';
				ans = i;
			}
		}
		std::cout << ans << std::endl;
	}
}