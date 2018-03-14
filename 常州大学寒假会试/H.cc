#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char *argv[]) {  
	long double A, B, C, D;
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> A >> B >> C;
		D = A/B*C;
//		std::cin >> D;
		std::string d = std::to_string(D);
		int dot = -1;
		for (int i = 0; i < d.length(); i++) {
			if (d[i] == '.') {
				dot = i;
				break;
			}
		}
		if (dot == -1) {
//			std::cout << "1  ";
			std::cout << d << ".00\n";
			continue;
		}
		d += "00000";
//		std::cout << d << '\n';
		if (d[dot+3] < '5') {
//			std::cout << "2  ";
			std::cout << std::fixed << std::setprecision(2) << D << std::endl;
		} else if (d[dot+3] > '5') {
//			std::cout << "3  ";
			std::cout << std::fixed << std::setprecision(2) << D+0.005 << std::endl;
		} else {
			bool yes = 0;
			for (int i = dot + 4; i < d.length(); i++) {
				if(d[i] > '0' && d[i] <= '9') {
					yes = 1;
					break;
				}
			}
			if (yes) {
//				std::cout << "4  ";
				std::cout << std::fixed << std::setprecision(2) << D+0.005 << std::endl;
			} else if ((int(d[dot+2]-'0'))%2==0) {
//				std::cout << "5  ";
				std::cout << std::fixed << std::setprecision(2) << D-0.005 << std::endl;
			} else {
//				std::cout << "6  ";
				std::cout << std::fixed << std::setprecision(2) << D+0.005 << std::endl;
			}
		}
	}
}