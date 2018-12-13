#include <iostream>
#include <vector>
#include <algorithm>

const int mod = 1e9+7;
const int maxn = 1e5+7;

using ll = long long;

int n;
std::vector<int> t[maxn];
int sta[maxn];

ll ori[maxn][2];
ll now[maxn][2];

void init() {
	memset(ori, 0, sizeof(ori));
	memset(now, -1, sizeof(now));
}

ll gaoori(int cur, int zo) {
	if (ori[cur][zo]) return ori[cur][zo];
	if (t[cur].size() == 0) {
		ori[cur][1] = 3;
		ori[cur][0] = 1;
		ori[cur][0] %= mod;
		ori[cur][1] %= mod;
		return ori[cur][zo];
	}
	if (t[cur].size() == 1) {
		ori[cur][1] = 2 * gaoori(t[cur][0], 0) + gaoori(t[cur][0], 1);
		ori[cur][0] = gaoori(t[cur][0], 1);
		ori[cur][0] %= mod;
		ori[cur][1] %= mod;
		return ori[cur][zo];
	}
	ori[cur][1] =  gaoori(t[cur][0], 0) * gaoori(t[cur][1], 0);
	ori[cur][1]	+= gaoori(t[cur][0], 0) * gaoori(t[cur][1], 1); 
	ori[cur][1] += gaoori(t[cur][0], 1) * gaoori(t[cur][1], 0);
	ori[cur][0] =  gaoori(t[cur][0], 1) * gaoori(t[cur][1], 1);
	ori[cur][0] %= mod;
	ori[cur][1] %= mod;
	return ori[cur][zo];
}

ll dfs(int cur, int zo) {
	if (now[cur][zo] != -1) return now[cur][zo];
	if (t[cur].size() == 0) {
		if (sta[cur] == -1) {
			now[cur][1] = 3;
			now[cur][0] = 1;
		} else if (sta[cur] == 0) {
			now[cur][0] = 4;
			now[cur][1] = 0;
		} else if (sta[cur] == 1) {
			now[cur][0] = 0;
			now[cur][1] = 4;
		}
		now[cur][1] %= mod;
		now[cur][0] %= mod;
		return now[cur][zo];
	}
	if (t[cur].size() == 1) {
		if (sta[cur] == -1) {
			now[cur][1] = 2 * dfs(t[cur][0], 0) + dfs(t[cur][0], 1);
			now[cur][0] = dfs(t[cur][0], 1);
			now[cur][1] %= mod;
			now[cur][0] %= mod;
		} else if (sta[cur] == 0) {
			now[cur][0] = 2 * (dfs(t[cur][0], 0) + dfs(t[cur][0], 1));
			now[cur][1] = 0;
			now[cur][1] %= mod;
			now[cur][0] %= mod;
		} else if (sta[cur] == 1) {
			now[cur][1] = 2 * (dfs(t[cur][0], 0) + dfs(t[cur][0], 1));
			now[cur][0] = 0;
			now[cur][1] %= mod;
			now[cur][0] %= mod;
		}
		return now[cur][zo];
	}
	if (sta[cur] == -1) {
		now[cur][1] =  dfs(t[cur][0], 0) * dfs(t[cur][1], 0);
		now[cur][1]	+= dfs(t[cur][0], 0) * dfs(t[cur][1], 1); 
		now[cur][1] += dfs(t[cur][0], 1) * dfs(t[cur][1], 0);
		now[cur][1] %= mod;
		now[cur][0] =  dfs(t[cur][0], 1) * dfs(t[cur][1], 1);
		now[cur][0] %= mod;
	} else if (sta[cur] == 0) {
		now[cur][0] =  dfs(t[cur][0], 0) * dfs(t[cur][1], 0);
		now[cur][0]	+= dfs(t[cur][0], 0) * dfs(t[cur][1], 1); 
		now[cur][0] += dfs(t[cur][0], 1) * dfs(t[cur][1], 0);
		now[cur][0] += dfs(t[cur][0], 1) * dfs(t[cur][1], 1);
		now[cur][0] %= mod;
		now[cur][1] = 0;
	} else if (sta[cur] == 1) {
		now[cur][1] =  dfs(t[cur][0], 0) * dfs(t[cur][1], 0);
		now[cur][1]	+= dfs(t[cur][0], 0) * dfs(t[cur][1], 1); 
		now[cur][1] += dfs(t[cur][0], 1) * dfs(t[cur][1], 0);
		now[cur][1] += dfs(t[cur][0], 1) * dfs(t[cur][1], 1);
		now[cur][1] %= mod;
		now[cur][0] = 0;
	}
	return now[cur][zo];
}

int main(int argc, char *argv[]) {  
	init();
	std::cin >> n;
	int x, y, f;
	for (int i = 1; i <= n; i++) {
		std::cin >> x >> y >> f;
		if(x) t[i].push_back(x);
		if(y) t[i].push_back(y);
		sta[i] = f;
	}
	ll ans = 0;
	ans = (dfs(1, 0) - gaoori(1, 1) + mod + mod) % mod;
	std::cout << ans << '\n';
}