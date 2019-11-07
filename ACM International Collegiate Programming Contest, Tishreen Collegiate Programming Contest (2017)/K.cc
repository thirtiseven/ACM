#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using ll = long long;
const ll maxc = 52;
const ll mod = 1e9+7;

ll c[maxc][maxc];

void init() {
	ll i,j;
	for (i = 0; i < maxc; i++) {
		c[i][0] = c[i][i] = 1;
	}
	for (i = 1; i < maxc; i++) {
		for(j = 1; j <= i; j++) {
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j] %= mod;
		}
	}
}

ll T;
std::string s;
std::vector<ll> v;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		ll now = 0;
		for (ll i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				now++;
			} else {
				v.push_back(now);
				now = 0;
			}
		}
		v.push_back(now);
		ll ans = 1, cur = 0;
		ll x = v.size();
//		std::cerr << x << '\n';
		if (x == 1) {
			cur = 0;
			for (ll j = 0; j <= v[0]-1; j++) {
				cur += c[v[0]-1][j];
				cur %= mod;
			}
			ans *= cur;
			ans %= mod;
		} else {
			for (ll j = 0; j <= std::min(v[0], v[x-1]); j++) {
				cur += c[v[0]][j] * c[v[x-1]][j];
				cur %= mod;
			}
			ans *= cur;
			ans %= mod;
			for (ll i = 1; i < x/2; i++) {
				cur = 0;
				for (ll j = 0; j <= std::min(v[i], v[x-i-1])+1; j++) {
					cur += c[v[i]+1][j] * c[v[x-i-1]+1][j];
					cur %= mod;
				}
				ans *= cur;
				ans %= mod;
			}
			if (x%2==1) {
				cur = 0;
				for (ll j = 0; j <= v[x/2]+1; j++) {
					cur += c[v[x/2]+1][j];
					cur %= mod;
				}
				ans *= cur;
				ans %= mod;
			}
		}
		std::cout << ans << '\n';
		v.clear();
	}
}