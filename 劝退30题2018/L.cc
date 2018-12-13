#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	while (std::cin >> n) {
		if (!n) exit(0);
		std::cout << (((n*n)%2==1)?"ailyanlu\n":"8600\n");
	}
}