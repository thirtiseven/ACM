#include <iostream>
#include <string>

int T;
int c[10];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		for (int i = 0; i <= 9; i++) {
			std::cin >> c[i];
		}
		int dig;
		int cnt = 1000000;
		for (int i = 1; i <= 9; i++) {
			if (c[i] < cnt) {
				dig = i;
				cnt = c[i];
			}
		}
		if (c[0] < cnt) {
			dig = 0;
			cnt = c[0];
		}
		if (dig == 0) {
			std::cout << "1";
			for (int i = 0; i <= cnt; i++) {
				std::cout << "0";
			}
			std::cout << '\n';
		} else {
			for (int i = 0; i <= cnt; i++) {
				std::cout << dig;
			}
			std::cout << '\n';
		}
	}
}