#include <iostream>
#include <algorithm>
#include <queue>

const int maxn = 1e5+7;
using ll = long long;

ll t[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		ll n, k;
		std::cin >> n >> k;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> t[i];
			sum += t[i];
		}
		std::priority_queue<ll> left;
		std::sort(t, t+n);
		ll tot = 1;
		ll now = k;
		ll num = 1;
		for (int i = n-1; i >= 0; i--) {
			tot--;
			if (tot < 0) {
				now += (k-left.top());
				left.pop();
				tot++;
				num++;
			}
			if (t[i] % k != 0) {
				left.push(t[i]%k);
			}
			tot += (t[i]/k);
			num += (t[i]/k);
			if (num >= n) {
				break;
			}
		}
		std::cout << sum + now << '\n';
	}
}