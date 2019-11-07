#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a[100002];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] = n+1-a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
}