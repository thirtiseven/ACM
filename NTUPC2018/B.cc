#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a, b, c;
	bool yes = 1;
	std::cin >> n;
	while(n--) {
		std::cin >> a >> b >> c;
		if(a+b<=c||a+c<=b||b+c<=a) {
			yes = 0;
			break;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
	return 0;
}