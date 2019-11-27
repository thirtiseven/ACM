#include <iostream>
#include <random>

int main(int argc, char *argv[]) {  
	std::cout << "10\n";
	std::mt19937 mt2(2); //32位
	for (int i = 0; i < 10; i++) {
		std::cout << "2000\n";
		for (int j = 0; j < 2000; j++) {
			std::cout << mt2() << " \n"[j==1999];
		}
		std::cout << '\n';
	}
}