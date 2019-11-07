#include <iostream>

using ll = long long;
const int maxn = 30000;

ll T, n, k, c[maxn];
ll sum;

bool check(ll x) {
	ll take = 0;
	ll tot = 0;
	for (ll i = 0; i < n; i++) {
		tot += (c[i]-take)/x;
		if (i < n-1 && (c[i]-take)%x+c[i+1] >= x) {
			tot++;
			take = x-(c[i]-take)%x;
		} else {
			take = 0;
		}
	}
	if (tot >= k) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		sum = 0;
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> c[i];
			sum += c[i];
		}
		ll l = 1, r = sum/k+1, mid;
		while (l <= r) {
			mid = (l+r)/2;
			if (check(mid)) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		if (!check(l)) {
			l--;
		}
		std::cout << l*k << '\n';
	}
}