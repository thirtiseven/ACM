#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	long long n, m, c;
	while (std::cin >> n >> m >> c) {
		long long a[maxn], s[maxn];
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			s[i] = s[i-1] + a[i];
		}
		std::sort(s, s+n+1);
		long long cnt = 0, ans = 0;
		while(cnt < m) {
			int t = s[n-cnt] - s[cnt];
			if (t < c) break;
			ans += (t-c);
			cnt++;
		}
		std::cout << ans << '\n';
	}
}