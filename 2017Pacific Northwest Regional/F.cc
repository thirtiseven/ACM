#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b, c;
	char add, equ;
	std::cin >> a >> add >> b >> equ >> c;
	std::cout << (a+b==c?"YES\n":"NO\n");
	return 0;
}