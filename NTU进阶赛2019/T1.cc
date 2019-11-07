#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, m, a[123];
	while (std::cin >> n >> m && n && m) {
		for (int i = 0; i < n; i++) std::cin >> a[i];
		a[n] = m;
		std::sort(a, a+n+1);
		for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
		std::cout << a[n] << '\n';
	}
}