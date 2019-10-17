#include <iostream>
#include <vector>

const int maxn = 3e5+7;
using ll = long long;

std::vector<int> t[maxn];
int n;
ll flow[maxn];

bool yes = 1;

ll dfs(int now, int fa) {
	if (t[now].size() == 0) {
		if (flow[now] > 0) {
			return flow[now];
		} else {
			return 0;
		}
	}
	ll res = 0;
	for (auto it: t[now]) {
		res += dfs(it, now);
	}
	if (flow[now] == 0) {
		flow[now] = res;
	} else {
		if (flow[i] != res) {
			yes = 0;
		}
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int x;
	for (int i = 2; i <= n; i++) {
		std::cin >> x;
		t[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> flow[i];
	}
}