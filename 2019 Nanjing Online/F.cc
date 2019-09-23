#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

const int maxn = 1e5+7;

int a[maxn];
std::vector<int> t[maxn];
int ans[maxn];

void dfs(int now, int fa) {
	ans[now] += ans[fa];
	ans[now] ++;
	for (auto it: t[now]) {
		dfs(it, now);
	}
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T;
	std::cin >> T;
	while (T--) {
		int n, k;
		for (int i = 0; i <= n; i++) {
			t[i].clear();
		}
		std::fill(ans, ans+maxn, 0);
		std::set<int> s;
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= k; i++) {
			s.insert(a[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (i+k <= n) {
				s.insert(a[i+k]);
			}
			if (i-k-1 > 0) {
				s.erase(a[i-k-1]);
			}
			auto it = s.find(a[i]);
			if (it == s.begin()) {
				t[0].push_back(a[i]);
			} else {
				it--;
				t[(*it)].push_back(a[i]);
			}
		}
		dfs(0, 0);
		for (int i = 1; i < n; i++) {
			std::cout << ans[i]-1 << ' ';
		}
		std::cout << ans[n]-1 << '\n';
	}
}