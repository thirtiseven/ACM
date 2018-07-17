#include <iostream>
#include <cmath>
#include <algorithm>

using LL = long long;
const int mod = 1000000007;

LL PowMod(LL a, LL b) { 
	a %= mod;
	LL ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % mod; 
		} 
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans; 
}


LL Inv(LL a) {
	return PowMod(a,mod-2);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		LL n, k;
		std::cin >> n >> k;
		LL ans = (PowMod(2, n)-1)%mod;
		LL now = 1;
		for (int i = 1; i < k; i++) {
			now = (now*(n-i+1))%mod;
			now = (now*Inv(i))%mod;
			ans = (ans - now + mod)%mod;
//			std::cout << now << " " << ans << '\n';
		}
		std::cout << "Case #" << tt << ": " << ans << "\n";
	}
}