#include <iostream>
#include <string>

std::string s;
int T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	int _;std::cin >> _;
	for (int i = 1; i <= _; i++) {
		std::cin >> s;
		bool T = 0, S = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a') {
				T = 1;
			} else if (s[i] == 'b') {
				S = 1;
			} else if (s[i] == 'c') {
				
			}
		}
	}
}