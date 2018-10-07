#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 105;
ll a[maxn], sum[maxn];
int main()
{
	ll n, d, ans;
	while (scanf("%lld%lld", &n, &d)) {
		ans = 0; d++;
		for (ll i = 1; i <= d; i++)
			sum[i] = i;
		for (ll i = d + 1; i <= n; i++)
			sum[i] = sum[i - 1] + sum[i - d] + 1;
		printf("%lld\n", (1ll << (n - 1)) - 1 - (sum[n - d]));
	}
	return 0;
}