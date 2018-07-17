#include <iostream>
#include <string>

std::string a[7];

char f(int d) {
	if (a[0][d+1] == '.') {
		if (a[1][d] == 'X') {
			return '4';
		}
		return '1';
	} else if (a[1][d] == '.') {
		if (a[4][d] == 'X') {
			return '2';
		} else if (a[3][d+1] == '.') {
			return '7';
		}
		return '3';
	} else if (a[1][d+3] == '.') {
		if (a[4][d] == 'X') {
			return '6';
		}
		return '5';
	} else if (a[3][d+1] == '.') {
		return '0';
	} else if (a[4][d] == 'X') {
		return '8';
	}
	return '9';
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T;
	std::cin >> T;
	while (T--) {
		for (int i = 0; i < 7; i++) {
			std::cin >> a[i];
		}
		std::cout << f(0);
		std::cout << f(5);
		std::cout << ":";
		std::cout << f(12);
		std::cout << f(17);
		std::cout << '\n';
	}
	
}