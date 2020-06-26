#include <iostream>

int T, a[12];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		bool zack = 0, mack = 0;
		for (int i = 0; i < 10; i++) {
			std::cin >> a[i];
			if (a[i] == 17) {
				zack = 1;
			} else if (a[i] == 18) {
				mack = 1;
			}
		}
		for (int i = 0; i < 10; i++) {
			std::cout << a[i] << " \n"[i==9];
		}		
		if (zack && mack) {
			std::cout << "both\n";
		} else if (zack) {
			std::cout << "zack\n";
		} else if (mack) {
			std::cout << "mack\n";
		} else {
			std::cout << "none\n";
		}
		std::cout << '\n';
	}
}