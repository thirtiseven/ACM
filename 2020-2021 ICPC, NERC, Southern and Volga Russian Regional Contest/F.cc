#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using ll = long long;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

ll T, n, x, y, u, v;

std::map<std::pair<ll, ll>, ll> mp;
std::vector<std::pair<ll, ll>> vec;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		mp.clear();
		vec.clear();
		std::cin >> n;
		for (ll i = 0; i < n; i++) {
			std::cin >> x >> y >> u >> v;
			std::pair<ll, ll> xx = std::make_pair(x-u, y-v);
			ll g = gcd(std::abs(x-u), std::abs(y-v));
			xx.first /= g;
			xx.second /= g;
//			std::cout << xx.first << ' ' << xx.second << '\n';
			mp[xx]++;
			vec.push_back(xx);
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			ans += mp[std::make_pair(-vec[i].first, -vec[i].second)];
		}
		ans /= 2;
		std::cout << ans << '\n';
	}
}