#include <iostream>
#include <string>

std::string s;
int n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	bool yes = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		if (s != "mumble" && s != std::to_string(i)) {
			yes = 0;
		}
	}
	std::cout << (yes?"makes sense":"something is fishy") << '\n'; 
}