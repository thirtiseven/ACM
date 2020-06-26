#include <iostream>
#include <string>

int t;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CAS = 1; CAS <= t; CAS++) {
		std::cin >> s;
		std::cout << "Case #" << CAS << ": ";
		int x = 0;
		for (int i = 0; i < s.length(); i++) {
			while (x < int(s[i]-'0')) {
				std::cout << '(';
				x++;
			}
			while (x > int(s[i]-'0')) {
				std::cout << ')';
				x--;
			}
			std::cout << s[i];
		}
		while (x > 0) {
			std::cout << ')';
			x--;
		}
		std::cout << '\n';
	}
}