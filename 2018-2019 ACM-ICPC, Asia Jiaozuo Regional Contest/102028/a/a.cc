#include <iostream>

int T;
int a[5];
int tot;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		tot = 0;
		for (int i = 0; i < 4; i++) {
			std::cin >> a[i];
			if (a[i]) {
				tot++;
			}
		}
		if (tot == 0) {
			std::cout << "Typically Otaku\n";
		} else if (tot == 1) {
			std::cout << "Eye-opener\n";
		} else if (tot == 2) {
			std::cout << "Young Traveller\n";
		} else if (tot == 3) {
			std::cout << "Excellent Traveller\n";
		} else if (tot == 4) {
			std::cout << "Contemporary Xu Xiake\n";
		}
	}
}