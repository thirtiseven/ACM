#include <iostream>
#include <queue>
#include <vector>

const int maxn = 5e4+7;

struct node { 
	int u;
	int d;
	node(int u, int d) :u(u), d(d){}
	bool operator < (const node &b) const{
		return d > b.d;
	}
};

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		std::vector<node> t[maxn];
		std::priority_queue<node> now;
		std::vector<int> ans;
		std::vector<int> query;
		int n, m, q, u, v, w, k;
		std::cin >> n >> m >> q;
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v >> w;
			t[u].push_back(node(v, w));
			now.push(node(v, w));
		}
		int maxq = 0;
		for (int i = 0; i < q; i++) {
			std::cin >> k;
			maxq = std::max(maxq, k);
			query.push_back(k);
		}
		int tot = 0;
		while (tot < maxq) {
			node cur = now.top();
			ans.push_back(cur.d);
			tot++;
			now.pop();
			for (auto it: t[cur.u]) {
				now.push(node(it.u, it.d+cur.d));
			}
		}
		for (int i = 0; i < q; i++) {
			std::cout << ans[query[i]-1] << '\n';
		}
	}
}