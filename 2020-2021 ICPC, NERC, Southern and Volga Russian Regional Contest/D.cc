#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

using ll = long long;

ll T, n, m, a, b, s[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> a >> b;
		for (ll i = 0; i < m; i++) {
			std::cin >> s[i];
		}
		std::sort(s, s+m);
		ll lit = std::abs(a-b)-1;
		ll tim = lit;
		if (a < b) {
			tim += a;
		} else {
			tim += n-a+1;
		}
		ll ans = 0, cnt = 0;
		for (ll i = 0; i < std::min(m, lit); i++) {
			if (s[i] > tim - lit + i + cnt) {
				cnt = s[i] - tim + lit - i;
			}
			if (i+cnt >= lit) {
				break;
			}
			if (s[i] <= tim - lit + i + cnt) {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}