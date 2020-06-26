#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int ans = std::max(s1.length(), s2.length());
	if (s1 == s2) {
		std::cout << "-1\n";
	} else {
		std::cout << ans << '\n';
	}
}