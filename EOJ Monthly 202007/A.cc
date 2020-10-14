#include <iostream>
#include <algorithm>
#include <string>

int T;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int res = 1;
		for (int i = 0; i < s.length()-1; i++) {
			if (s[i] == s[i+1]) {
				if (s[i] == 'a') {
					res = 2;
				} else {
					res = 3;
				}
			}
		}
		if (s[0] == 'b') {
			res = 3;
		}
		if (s == ) {
			std::cout << "Happy Fang\n";
		} else if (res == 1 || res == 2) {
			std::cout << "Sad Fang\n";
		} else {
			std::cout << "Dead Fang\n";
		}
	}
}