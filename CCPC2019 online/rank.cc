#include <iostream>
#include <set>
#include <string>

std::set<std::string> ss;

int main(int argc, char *argv[]) {  
	std::string s;
	while (std::cin >> s) {
		ss.insert(s);
		std::cout << ss.size() << '\n';
	}
}