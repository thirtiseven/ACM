#include <iostream>

int T, u[3], r[3];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		int ucount = 0, rcount = 0;
		for (int i = 0; i < 3; i++) {
			std::cin >> u[i];
			ucount += u[i];
		}
		for (int i = 0; i < 3; i++) {
			std::cin >> r[i];
			rcount += r[i];
		}
		for (int i = 0; i < 3; i++) {
			std::cout << u[i] << " ";
		}
		for (int i = 0; i < 3; i++) {
			std::cout << r[i] << " \n"[i==2];
		}
		bool count = 0, color = 0;
		if (ucount > rcount) {
			count = 1;
		}
		if (u[0] == r[0]) {
			if (u[1] == r[1]) {
				if (u[2] > r[2]) {
					color = 1;
				}
			} else if (u[1] > r[1]) {
				color = 1;
			}
		} else if (u[0] > r[0]) {
			color = 1;
		}
		if (count && color) {
			std::cout << "both\n";
		} else if (count) {
			std::cout << "count\n";
		} else if (color) {
			std::cout << "color\n";
		} else {
			std::cout << "none\n";
		}
		std::cout << '\n';
	}
}