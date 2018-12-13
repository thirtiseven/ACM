#include <iostream>
#include <random>

int main(int argc, char *argv[]) {  
	std::mt19937 ra(0);
	std::string s = "LURD";
	for (int i = 0; i < 50000; i++) {
		std::cout << s[ra()%4];
	}
}