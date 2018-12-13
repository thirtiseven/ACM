#include <iostream>
#include <algorithm>

const int maxn = 1234;

int a[maxn], n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	std::cout << a[n-1]-a[0]-n+1 << '\n';
}