#include <iostream>
#include <cstring>
#include <algorithm>

using ll = long long;
const int maxl = 13;
const int maxn = 108+7;

int bit[maxl];
ll dp[maxl][maxn][maxn][maxn];
// dp[当前位数][digtal和][当前的模数][余数];
ll maxdigsum;

ll dfs(int pos, ll digsum, ll mod, ll sum, bool lead, bool limit) {
	if (pos == -1) {
		return (digsum == mod) && (sum % digsum == 0);
	}
	if(!limit && !lead  && dp[pos][int(digsum)][int(mod)][int(sum%mod)] != -1) return dp[pos][int(digsum)][int(mod)][int(sum%mod)];
	ll up = limit ? bit[pos] : 9;
	ll ans = 0;
	for (ll i = 0; i <= up; i++) {
		if (digsum + i > mod || digsum + i + 9 * (pos+1) < mod) {
			break;
		}
		ll newdig = digsum + i; 
		ll newsum = sum*10 + i;
		ans += dfs(pos-1, newdig, mod, newsum, lead && i == 0, limit && i==bit[pos]);
	}
	if (!limit && !lead) {
		dp[pos][int(digsum)][int(mod)][int(sum%mod)] = ans;
	}
	return ans;
}

ll gao(ll x) {
	int cnt = 0;
	while (x) {
		bit[cnt++] = x % 10;
		x /= 10;
	}
	maxdigsum = cnt*9;
	ll res = 0;
	for (ll i = 1; i <= maxdigsum; i++) {
		res += dfs(cnt-1, 0, i, 0, true, true);
	}
	return res;
}

int main(int argc, char *argv[]) {  
	ll l;
	int T;
	std::cin >> T;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= T; i++) {
		std::cin >> l;
		std::cout << "Case " << i << ": " << gao(l) << '\n';
	}
}