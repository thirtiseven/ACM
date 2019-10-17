#include <iostream>

using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e5+7;

//ll PowMod(ll a, ll b, const ll &Mod) { 
//	a %= Mod;
//	ll ans = 1; 
//	while(b) {
//		if (b & 1){
//			ans = (ans * a) % Mod; 
//		} 
//		a = (a * a) % Mod;
//		b >>= 1;
//	}
//	return ans; 
//}
//
//ll Inv(ll a, ll n){ 
//	return PowMod(a, n-2, n);
//}
//
//
//ll C(const ll &n, const ll &m, const int &pr) {
//	ll ans = 1;
//	for (ll i = 1; i <= m; i++) {
//		ll a = (n - m + i) % pr;
//		ll b = i % pr;
//		ans = (ans * (a * Inv(b, pr)) % pr) % pr;
//	}
//	return ans;
//}

ll CC[maxn][5];

ll T, n, m;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	CC[0][0] = 1;
	for (int i = 1; i < maxn; i++) {
		CC[i][0] = 1;
		for (int j = 1; j <= 4; j++) {
			CC[i][j] = (CC[i-1][j] + CC[i-1][j-1]) % mod;
		}
	}
	
	std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		std::cin >> n >> m;
		if (n < 3 || m < 3) {
			std::cout << "Case " << _ << ": " << "0" << '\n';
		} else {
			std::cout << "Case " << _ << ": " << ((CC[n][3] + CC[n][4] % mod) * ((CC[m][3] + CC[m][4]) % mod)) % mod << '\n';
		}
	}
}