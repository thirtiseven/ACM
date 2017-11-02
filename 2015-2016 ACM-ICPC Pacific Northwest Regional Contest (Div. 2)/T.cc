#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int a[4], b[4];
	for(int i = 0; i < 3; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < 3; i++) {
		std::cin >> b[i];
	}
	std::sort(a, a+3);
	std::sort(b, b+3);
	if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	return 0;
}