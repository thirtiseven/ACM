#include <iostream>
 
const int maxn = 1e5+7;
using ll = long long;
 
ll n, c, t, p[maxn];
 
bool check(ll x) {
	ll now = 0, tot = 0;
	for (ll i = 0; i < n; i++) {
		now += p[i];
		if (now > x) {
			now -= p[i];
			if (now > x) {
				return false;
			}
			tot++;
			now = p[i];
		}
	}
	if (now > 0) {
		if (now > x) {
			return false;
		}
		tot++;
	}
	if (tot > c) {
		return false;
	}
	return true;
}
 
int main(int argc, char *argv[]) {  
	std::cin >> n >> c >> t;
	ll sum = 0, minn = 0;
	for (ll i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	ll l = 0, r = 100000000000, mid;
	while (l <= r) {
		mid = (l+r)/2ll;
		if (!check(mid)) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	while (check(l)) {
		l--;
	}
	l++;
	std::cout << l/t+ll(l%t>0) << '\n';
}