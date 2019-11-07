#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <set>

using ll = long long;

std::map<ll, ll> mp;

struct pll {
	ll first, second;
	pll(ll a = 0, ll b = 0) {
		first = a, second = b;
	}
	bool operator < (const pll &a) const {
		return second > a.second;
	}

};

std::set<pll> s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll n;
	std::cin >> n;
	ll u, v;
	for (ll i = 0; i < n; i++) {
		std::cin >> u >> v;
		if (u > v) {
			std::swap(u, v);
		}
		mp[u] = std::max(mp[u], v);
	}
	ll oneans = 0;
	for (auto it: mp) {
		oneans = std::max(it.first * it.second, oneans);
		s.insert(pll(it.first, it.second));
	}
	ll twoans = 0;
	for (auto it: mp) {
		s.erase(pll(it.first, it.second));
		if (s.empty()) break;
		twoans = std::max(twoans, std::min(it.first, s.begin()->first)*std::min(it.second, s.begin()->second));
	}
	if (twoans*2 <= oneans) {
		std::cout << oneans/2ll << (oneans%2ll?".5":".0") << '\n';
	} else {
		std::cout << twoans << ".0" << '\n';
	}
}