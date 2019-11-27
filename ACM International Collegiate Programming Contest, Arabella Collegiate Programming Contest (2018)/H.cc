#include <iostream>
#include <string>
#include <cstring>

const int maxc = 27;
const int maxn = 1e5+7;
using ll = long long;

ll T, n, m, k;
std::string a, b;
ll app[maxc][maxc], cnt[maxn][maxc], ans[maxc][maxc];
ll res = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		memset(app, 0, sizeof(app));
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		std::cin >> n >> m >> k;
		std::cin >> a >> b;
		cnt[0][int(b[0]-'a')]++;
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < 26; j++) {
				cnt[i][j] = cnt[i-1][j];
			}
			cnt[i][int(b[i]-'a')]++;
		}
		for (int i = m-1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				ans[j][int(b[i]-'a')] += cnt[i][j];
			}
		}
		res = 0;
		for (int i = 0; i + k - 1 < n; i++) {
//			std::cout << a[i] << ' ' << a[i+k-1] << ' ' << ans[int(a[i]-'a')][int(a[i+k-1]-'a')] << '\n';
			if (!app[int(a[i]-'a')][int(a[i+k-1]-'a')]) {
				res += ans[int(a[i]-'a')][int(a[i+k-1]-'a')];
			}
			app[int(a[i]-'a')][int(a[i+k-1]-'a')] = 1;
		}
		std::cout << res << '\n';
	}
}