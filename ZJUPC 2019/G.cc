#include <iostream>
#include <algorithm>
#include <cmath>

#define maxn 100007
long long a1[maxn], a2[maxn], aa;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--) {
		long long n, k;
		std::cin >> n >> k;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> aa;
			if(aa > 0) {
				a1[cnt1] = aa;
				cnt1++;
			} else if(aa < 0) {
				a2[cnt2] = -aa;
				cnt2++;
			}
		}
		std::sort(a1, a1+cnt1);
		std::sort(a2, a2+cnt2);
		long long ans = 0;
		for(int i = cnt1-1; i >= 0; i -= k) {
			ans += 2 * a1[i];
		}
		for(int i = cnt2-1; i >= 0; i -= k) {
			ans += 2 * a2[i];
		}
		ans -= std::max(a1[cnt1-1], a2[cnt2-1]);
		std::cout << ans << '\n';
	}
}