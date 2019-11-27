#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int maxn = 100005;
string a, b;
ll cnt[30];
ll add[30][30];
ll f[30][30];
int main()
{
	ll T, n, m, k;
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		memset(add, 0, sizeof(add));
		memset(f, 0, sizeof(f));
		cin >> n >> m >> k;
		cin >> a >> b;
		for (ll i = n - 1; i >= 0; i--) {
			ll idx = a[i] - 'a';
			cnt[idx]++;
			for (ll j = 0; j < 26; j++) {
				add[idx][j] += cnt[j];
			}
		}
		ll ans = 0;
		for (ll i = 0; i + k - 1 < m; i++) {
			ll l = b[i] - 'a', r = b[i + k - 1] - 'a';
			if (f[l][r]) continue;
			f[l][r] = 1;
			ans += add[l][r];
		}
		cout << ans << endl;
	}
	return 0;
}