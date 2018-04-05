#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

const int maxn = 123;

int main(int argc, char *argv[]) {  
	int n;
	double w[maxn];
	std::string s[maxn];
	int dot[maxn];
	int integer[maxn];
	int length[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		w[i] = std::stod(s[i]);
		for (int j = 0; j < s[i].length(); j++) {
			if (j == s[i].length()-1) {
				dot[i] = -1;
			} else if (s[i][j] == '.') {
				dot[i] = j;
				break;
			}
		}
		integer[i] = floor(w[i]);
		w[i] = std::stod(s[i].substr(dot[i]));
		
		std::cout << w[i] << " " << s[i] << " " << integer[i] << " " << dot[i] << '\n';
		
		for (int j = 2; j <= 128; j *= 2) {
			for (int h = 1; h < j; h++) {
				double now = double(h)/(double)j;
				now -= fmod(now, pow(0.1, double(s[i].length()-dot[i])));
				if (w[i] == now) {
					std::cout << "YYYYYYYEEEEEEEES\n";
					//YESSSSS
					goto endOfTheWorld;
				}
				std::cout << now << " " << w[i] << '\n';
				now += pow(0.1, double(s[i].length()-dot[i]));
				if (w[i] == now) {
					std::cout << "YYYYYYYEEEEEEEES\n";
					//YESSSSS
					goto endOfTheWorld;
				}
				std::cout << now << " " << w[i] << '\n';
			}
		}
		endOfTheWorld:
		;
	}
}