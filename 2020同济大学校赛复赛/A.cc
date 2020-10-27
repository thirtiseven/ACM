#include <iostream>
#include <algorithm>

using ll = long long;

const ll mod = 1e9+7;

ll n, k;

ll A(ll x) {
	return (x * (x-1) % mod) * (x-2) % mod;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	n++;
	ll a = n/k, b = n%k, c = k-(n%k);
	ll ans = (c * A(a) % mod + b * A(a+1) % mod) % mod;
	std::cout << ans << '\n';
}