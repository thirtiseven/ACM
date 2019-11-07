#include <iostream>
#include <algorithm>

const int maxn = 8000+7;

using ll = long long;

ll num[maxn];
ll n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	ll temp;
	for (ll i = 0; i < n; i++) {
		std::cin >> temp;
		num[temp]++;
	}
	std::sort(num+1, num+k+1);
	ll ans = INT64_MAX;
	for (ll i = 0; i <= k; i+=2) {
		ll maxx = num[k];
		for (ll j = 0; j < i; j++) {
			maxx = std::max(maxx, num[j+1] + num[i-j]);
		}
		ans = std::min(ans, maxx*(i/2+(k-i)));
	}
	std::cout << ans << '\n';
}