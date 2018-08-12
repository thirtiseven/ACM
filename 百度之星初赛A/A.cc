#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	int a[1234];
	while (std::cin >> n) {
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];	
		}
		std::sort(a, a+n);
		int ans = -1;
		for (int i = 0; i+2<n; i++) {
			if (a[i]+a[i+1]>a[i+2] && a[i]+a[i+2]>a[i+1] && a[i+2]+a[i+1]>a[i]) {
				ans = std::max(ans, a[i] + a[i+1] + a[i+2]);
			}
		}
		std::cout << ans << '\n';
	}
}