#include <iostream>
#include <algorithm>

using ll = long long;

int main(int argc, char *argv[]) {  
	int T;
	ll k, a[10];
	std::cin >> T;
	while (T--) {
		std::cin >> k;
		ll cnt = 0;
		for (ll i = 0; i < 7; i++) {
			std::cin >> a[i];
			if (a[i]) {
				cnt++;
			}
		}
		ll ans = 0;
		if (k > cnt*2ll) {
			ans = (k/cnt-1LL)*7ll;
			k %= cnt;
			k += cnt;
		}
		ll now = 200000000;
		ll tot;
		for (ll i = 0; i < 7; i++) {
			cnt = 0;
			tot = 0;
			for (ll j = i; cnt < k; j = (j+1)%7, tot++) {
				if (a[j] == 1) cnt++;
			}
			now = std::min(now, tot);
		}
		if (now == 200000000) {
			now = 0;
		}
		ans += now;
		std::cout << ans << '\n';
	}
}