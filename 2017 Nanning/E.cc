#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>

using ll = unsigned long long;
using ld = long double;

#define mp std::make_pair

std::map<std::pair<ll, ll>, ld> me;
ll r, k;
ld p, t;

ld gao(ll l, ll r) {
	if (me.find(mp(l, r)) != me.end()) return me[mp(l, r)];
	if (l == 0) {
		t = p*gao(0, r>>1);
		me[mp(l, r)] = t;
		return t;
	}
	if (r == 0) {
		t = (1.0-p)*gao(l>>1, 0);
		me[mp(l, r)] = t;
		return t;
	}
	if (!(l&1)) {
		t = p*gao(l>>1, r>>1);
		me[mp(l, r)] = t;
		return t;
	} else {
		t = p*(p*gao((l>>1)+1, (r>>1)-1) + (1.0-p)*gao(l>>1, r>>1));
		me[mp(l, r)] = t;
		return t;
	}
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T;
	std::cin >> T;
	while (T--) {
		me.clear();
		std::cin >> r >> k >> p;
		me[mp(0,1)] = p;
		me[mp(1,0)] = (1.0-p);
		ll num = 1LL<<r;
		ll l = k-1, r = num-k;
		if (p < 0.5) {
			std::swap(l, r);
		}
		std::cout << std::fixed << std::setprecision(6) << gao(l, r) << '\n';
	}
}