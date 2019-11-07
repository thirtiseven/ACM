#include <iostream>
#include <set>
#include <map>
#include <vector>

const int maxn = 1e5+7;

int T, n;
std::pair<int, int> e[maxn];
std::set<int> v;
std::map<int, int> col;
std::map<int, std::vector<int>> t;
std::map<std::pair<int, int>, int> num;
std::vector<std::tuple<int, int, int>> ans;
int last, laste;

void init() {
	last = -1, laste = -1;
	v.clear();
	col.clear();
	t.clear();
	num.clear();
	ans.clear();
}

void dfs(int now, int fa, int c) {
	col[now] = c;
	last = now;
	laste = num[std::make_pair(now, fa)];
	for (auto it: t[now]) {
		if (col.find(it) == col.end()) {
			dfs(it, now, c);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	std::cin >> T;
	while (T--) {
		init();
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> e[i].first >> e[i].second;
			v.insert(e[i].first);
			v.insert(e[i].second);
			t[e[i].second].push_back(e[i].first);
			t[e[i].first].push_back(e[i].second);
			num[e[i]] = i;
			num[std::make_pair(e[i].second, e[i].first)] = i;
		}
		int colour = 0;
		int dis;
		for (auto it: v) {
			colour++;
			if (col.find(it) == col.end()) {
				dfs(it, -1, colour);
				if (colour == 1) {
					dis = last;
				} else {
					if (laste <= 0) continue;
					ans.push_back(std::make_tuple(laste, last, dis));
				}
			}
		}
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << std::get<0>(it) << ' ' << std::get<1>(it) << ' ' << std::get<2>(it) << '\n';
		}
	}
}