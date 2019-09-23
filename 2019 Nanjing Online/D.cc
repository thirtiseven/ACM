#include <iostream>
#include <vector>
#include <queue>

const int maxn = 2e5+7;

double ans[maxn];
std::vector<int> t[maxn];
int n, m;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::fill(ans, ans+maxn, 0);
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			t[i].clear();
		}
		int u, v;
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v;
			t[u].push_back(v);
		}
		std::queue<int> q;
		q.push(1);
		ans[1] = 0;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			double c = 1.0/(double(t[now].size())+1);
			double cc = c/((1-c)*(1-c));
			double ccc = c/(1-c);
			for (auto it: t[now]) {
				ans[it] += cc;
				ans[it] += (ans[now]) * ccc;
				q.push(it);
			}
		}
		std::cout << ans[n] << '\n';
	}
}