#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;
int a[maxn];
int n;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	int n;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		if (n <= 4) {
			std::cout << "0\n";
			continue;
		}		
		int ans = 0;
		for (int i = 1; i < n-1; i++) {
			if (a[i-1] < a[i] && a[i] > a[i+1]) {
				ans++;
			}
		}
		int minus = 0;
		if (a[0] < a[1] && a[1] > a[2]) minus = 1;
		if (a[n-3] < a[n-2] && a[n-2] > a[n-1]) minus = 1;
		for (int i = 2; i < n-2; i++) {
			int temp = 0;
			int xx = 0;
			if (a[i-2] < a[i-1] && a[i-1] > a[i]) temp++;
			if (a[i-1] < a[i] && a[i] > a[i+1]) temp++;
			if (a[i] < a[i+1] && a[i+1] > a[i+2]) temp++;
			if (a[i-2] < a[i-1] && a[i-1] > a[i+1]) xx++;
			if (a[i-1] < a[i+1] && a[i+1] > a[i+2]) xx++;
			minus = std::max(minus, temp-xx);
		}
		std::cout << ans-minus << '\n';
	}
}