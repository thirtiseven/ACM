#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int ans = 1;
	int l = 1;
	char last = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != last) {
			l++;
			last = s[i];
		}
	}
	std::cout << pow(2,(l-10));
}