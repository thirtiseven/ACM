#include <iostream>
#include <algorithm>

using ll = long long;
const int maxn = 1e5+7;

ll l[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);   
	int T;
	std::cin >> T;
	for (int CC = 1; CC <= T; CC++) {
		ll a, b, n;
		std::cin >> a >> b >> n;
		for (int i = 1; i <= a; i++) {
			std::cin >> l[i];
		}
		ll add[maxn];
		add[0] = 0;
		for (int i = 1; i <= a; i++) {
			add[i] = add[i-1] + l[i];
		}
		ll now = a+b;
		while (n--) {
			a = std::upper_bound(add, add+a, now) - add;
			b = now - add[a];
			std::cout << a << " " << b << '\n';
		}
	}
}