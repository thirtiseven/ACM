#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 201320
#define mod 530600414
#define ll long long

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	ll len[maxn], ans[maxn], dis[maxn], num[maxn], sum[maxn];
	memset(ans, 0, sizeof(ans));
	ans[5] = 5, ans[6] = 16, num[5] = 2, num[6] = 3, dis[5] = 11, dis[6] = 22, len[5] = 8, len[6] = 13, sum[5] = 5, sum[6] = 17;
	for(int i = 7; i < 201316; i++) {
		len[i] = (len[i-1] + len[i-2]) % mod;
		dis[i] = (dis[i-1] + dis[i-2] + (len[i-1] * num[i-2]) % mod) % mod;
		sum[i] = (sum[i-2] + sum[i-1] + (num[i-1] * len[i-2]) % mod) % mod;
		num[i] = (num[i-1] + num[i-2]) % mod;
		ans[i] = (ans[i-1] + ans[i-2] + (dis[i-2] * num[i-1]) % mod + (sum[i-1] * num[i-2]) % mod) % mod;
	}
	int t;
	std::cin >> t;
	for(int circle = 1; circle <= t; circle++) {
		ll n;
		std::cin >> n;
		std::cout << "Case #" << circle << ": " << ans[n] << "\n";
	}
	return 0;
}