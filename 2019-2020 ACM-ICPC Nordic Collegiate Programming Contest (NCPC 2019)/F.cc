#include <iostream>
#include <vector>

const int maxn = 3e5+7;
using ll = long long;

std::vector<int> t[maxn];
int n;
ll flow[maxn], upper[maxn];

bool yes = 1;

std::pair<ll, ll> dfs1(int now, int fa) {
	if (t[now].size() == 0) {
		if (flow[now] > 0) {
			upper[now] = flow[now];
			return std::make_pair(flow[now], flow[now]);
		} else {
			upper[now] = 1;
			return std::make_pair(0, 1);
		}
	}
	ll sum = 0, uppersum = 0;
	std::pair<ll, ll> temp;
	bool all = 1;
	for (auto it: t[now]) {
		temp = dfs1(it, now);
		if (temp.first) {
			sum += temp.first;
		} else {
			all = 0;
		}
		uppersum += temp.second;
	}
	if (flow[now] == 0 && all) {
		flow[now] = sum;
	}
	if (flow[now] == 0) {
		upper[now] = uppersum;
	} else {
		upper[now] = flow[now];
	}
	return std::make_pair(flow[now], upper[now]);
}

void dfs2(int now, int fa) {
	if (flow[now] > 0) {
		ll sum = 0, unknownupper = 0, unknown = 0;
		for (auto it: t[now]) {
			if (flow[it] == 0) {
				unknownupper += upper[it];
				unknown++;
			} else {
				sum += flow[it];
			}
		}
		if (unknown == 1) {
			for (auto it: t[now]) {
				if (flow[it] == 0) {
					flow[it] = flow[now] - sum;
					break;
				}
			}
		} else if (unknown > 1 && flow[now] - sum == unknownupper) {
			for (auto it: t[now]) {
				if (flow[it] == 0) {
					flow[it] = upper[it];
				}
			}		
		}
	}
	for (auto it: t[now]) {
		dfs2(it, now);
	}
}

void dfs3(int now, int fa) {
	if (flow[now] <= 0) {
		flow[now] = std::max(1ll, upper[now]);
	}
	if (t[now].size()==0) {
		return;
	}
	ll sum = 0;
	for (auto it: t[now]) {
		sum += flow[it];
	}
	if (sum != flow[now]) {
		yes = 0;
		return;
	}
	for (auto it: t[now]) {
		dfs3(it, now);
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
		upper[i] = flow[i];
	}
	dfs1(1, -1);
	dfs2(1, -1);
//	for (int i = 1; i <= n; i++) {
//		std::cerr << flow[i] << ' ' << upper[i] << '\n';
//	}
	if (yes) {
		dfs3(1, -1);
	}
	if (yes == 0) {
		std::cout << "impossible\n";
	} else {
		for (int i = 1; i <= n; i++) {
			std::cout << flow[i] << '\n';
		}
	}
}