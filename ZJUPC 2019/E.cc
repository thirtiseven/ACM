#include <iostream>

const int maxn = 123;
#define ll long long

ll a[maxn], b[maxn];
int T, n;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		a[n+1] = 0;
		b[n+1] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		bool yes = 1;
		for (int i = n; i >= 1; i--) {
			if (a[i] >= b[i]) {
				yes = 0;
				break;
			}
			b[i] -= a[i];
			b[i-1] += b[i];
		}
		if (yes) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}