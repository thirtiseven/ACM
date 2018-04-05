#include <string>
#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
	int T ;
	std::cin >> T ;
	while (T--) {
		std::map<std::string, int> firstset;
		int n;
		std::cin >> n;
		std::string s;
		for (int i=0; i<n; i++) {
			std::cin >> s;
			firstset[s] = i;
		}
		int first = 0;
		int last = 0;
		for (int i=0; i<n; i++) {
			std::cin >> s;
			int loc = firstset[s];
			if (loc > last)
				last = loc ;
			if (last == i) {
				if (first)
					std::cout << " " ;
				std::cout << (last-first+1) ;
				first = i + 1 ;
				last = first ;
			}
		}
		std::cout << std::endl ;
	}
}