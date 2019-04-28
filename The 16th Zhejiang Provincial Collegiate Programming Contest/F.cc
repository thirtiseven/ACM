#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::string s;
		std::cin >> s;
		std::cout << s[0];
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'y' || s[i] == 'o' || s[i] == 'u') {
				continue;
			}
			std::cout << s[i];
		}
		std::cout << '\n';
	}
}