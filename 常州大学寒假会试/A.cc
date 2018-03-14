#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int i;
	for (i = 0; i < (s.length()-3)%3; i++) {
		std::cout << s[i];
		if (i == (s.length()-3)%3 - 1) {
			std::cout << ',';
		}
	}
	int cnt = 0;
	for (;i < s.length(); i++) {
		std::cout << s[i];
		cnt++;
		if (cnt % 3 == 0 && i != s.length()-1) {
			std::cout << ',';
		}
	}
}