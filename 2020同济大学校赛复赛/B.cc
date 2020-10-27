#include <iostream>
#include <algorithm>
#include <string>

int T, k;
std::string C;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> C >> k;
		int ans = 0;
		int start = 0;
		while (C[start] == 0) {
			start++;
		} 
		bool zero = 0;		
		for (int i = C.length()-1; i >= start; i--) {
			if (C[i] != '0' && k > 0) {
				ans++;
			} else {
				zero = 1;
				k--;
			}
		}
		if (!zero) {
			std::cout << "-1\n";
		} else if (k > 0) {
			std::cout << C.length()-1 << '\n';
		} else {
			std::cout << ans << '\n';
		}
	}
}