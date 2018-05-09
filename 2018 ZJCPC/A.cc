#include <iostream>
const int maxn = 1e5+9;
long long a[maxn], n, T, cnt, yes;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while(T--) {
		yes = 1;
		cnt = 1;
		std::cin >> n;
		std::cin >> a[1];
		bool y = 1;
		for (int i = 2; i <= n; i++) {
			std::cin >> a[i];
			if (a[i] > a[i-1] && y) {
				cnt = i;
			} else {
				y = 0;
			}
		}
		for (int i = cnt+1; i <= n; i++) {
			if (a[i] >= a[i-1]) {
				yes = 0;
				break;
			}
		}
//		std::cout << cnt << '\n';
		if (cnt == n || cnt == 1) {
			yes = 0;
		}
		std::cout << (yes?"Yes\n":"No\n");
	}
}