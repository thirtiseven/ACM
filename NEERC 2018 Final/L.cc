#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using ll = long long;
const int maxn = 1e5+8;

int main(int argc, char *argv[]) {  
	ll n, k;
	ll a[maxn], b[maxn], ans[maxn], vis[maxn];
	std::fill(ans, ans+maxn, 0);
	std::fill(vis, vis+maxn, 0);
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ans[a[i]] = std::max(ans[a[i]], b[i]);
	}
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> left;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ans[a[i]] == b[i] && !vis[a[i]]) {
			cnt++;
			vis[a[i]] = 1;
		} else {
			left.push(b[i]);
		}
	}
	while (cnt < k) {
		res += left.top();
		left.pop();
		cnt++;
	}
	std::cout << res << '\n';
}