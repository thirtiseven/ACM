#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

const int maxn = 1e5+7;
using ll = long long;

ll n;
std::vector<std::pair<ll, ll>> s;
std::map<ll, ll> h, v;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	ll T;
	std::cin >> T; 
	for (ll _ = 1; _ <= T; _++) {
		s.clear();
		h.clear();
		v.clear();
		std::cin >> n;
		ll x, y;
		for (ll i = 0; i < n; i++) {
			std::cin >> x >> y;
			s.push_back(std::make_pair(x, y));
			h[x]++;
			v[y]++;
		}
		ll maxh = 0, maxv = 0;
		ll ans1 = 0, ans2 = 0;
		for (auto it: h) {
			maxh = std::max(it.second, maxh);
		}
		for (auto it: v) {
			maxv = std::max(it.second, maxv);
		}
		for (auto it: s) {
			if (h[it.first] == maxh && v[it.second] == maxv) {
				ans1 = maxh + maxv - 1;
				ans2 ++;
			}
		}
		ll numh = 0, numv = 0, numsech = 0, numsecv = 0;
		for (auto it: h) {
			if (it.second == maxh) {
				numh++;
			}
			if (it.second == maxh-1) {
				numsech++;
			}
		}
		for (auto it: v) {
			if (it.second == maxv) {
				numv++;
			}
			if (it.second == maxv-1) {
				numsecv++;
			}
		}
		if (v.size() == 1 && h.size() == 1) {
			ans1 = 1, ans2 = 1;
		} else if (maxh == 1 && maxv == 1) {
			ans1 = 2, ans2 = n*(n-1)/2;
		} else if (ans2 < numh * numv) {
			ans1 = maxh + maxv;
			ans2 = numh * numv - ans2;
		} else {
			ans2 += numsech * numv + numsecv * numh;
			for (auto it: s) {
				if (h[it.first] == maxh-1 && v[it.second] == maxv) {
					ans2--;
				}
				if (h[it.first] == maxh && v[it.second] == maxv-1) {
					ans2--;
				}
			}
		}
		std::cout << "Case " << _ << ": " << ans1 << ' ' << ans2 << '\n';
	}
}