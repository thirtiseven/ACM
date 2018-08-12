#include <iostream>

int main(int argc, char *argv[]) {  
	double a[1004];
	a[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		a[i] = (1+a[i-1])/(2*i-1);
		
		std::cout << a[i] << '\n';
	}
}