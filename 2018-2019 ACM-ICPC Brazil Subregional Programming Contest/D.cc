#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int a;
	int ans = 0;
	for (int i =0; i < n; i++) {
		std::cin >> a;
		if (a!=1) {
			ans++;
		}
	}
	std::cout << ans;
}