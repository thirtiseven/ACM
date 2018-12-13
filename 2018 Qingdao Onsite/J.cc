#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;
using ll = long long;

ll T, n, m, a[maxn];
std::vector<ll> v;888jj8

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		v.clear();
		int cnt = 0, sum = 0;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			if (a[i] == 0) {
				cnt++;
			} else {
				v.push_back(a[i]);
			}
		}
		ll ans = 0;
		if (n == m) {
			std::cout << "Richman\n";
		} else if (m < cnt) {
			std::cout << "Impossible\n";
		} else {
			for (int i = 0; i < m-cnt; i++) {
				ans += v[i];
			}
			ll minn = 1e18;
			for (int i = m-cnt; i < v.size(); i++) {
				minn = std::min(minn, v[i]);
			}
			ans += minn-1;
			std::cout << ans << '\n';
		}
	}
}