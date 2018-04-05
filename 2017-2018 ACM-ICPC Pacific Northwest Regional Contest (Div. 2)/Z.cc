#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	n++;
	std::string s;
	s = std::to_string(n);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			for (int j = i; j < s.length(); j++) {
				s[j] = '1';
			}
		}
	}
	std::cout << s;
}