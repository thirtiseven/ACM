#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int a[5];
	for (int i = 0; i < 4; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+4);
	std::cout << std::abs(a[0]+a[3]-(a[1]+a[2])) << '\n';
}