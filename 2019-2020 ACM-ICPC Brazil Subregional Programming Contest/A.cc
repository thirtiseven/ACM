#include <iostream>
#include <vector>
#include <cmath>

const int maxn = 1024;

using ll = long long;

ll n, m;
int k;

struct round{
	ll x, y, r;
} c[maxn];

int fa[maxn];

void init(int xx) {
	for (int i = 1; i <= xx; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

ll dis(ll a, ll b) {
	return (c[a].x-c[b].x)*(c[a].x-c[b].x)+(c[a].y-c[b].y)*(c[a].y-c[b].y);
}

int main(int argc, char *argv[]) {  
	std::cin >> m >> n >> k;
	init(k+3);
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i].x >> c[i].y >> c[i].r;
		if (c[i].x <= c[i].r || n-c[i].y <= c[i].r) {
			unin(k+1, i);
		}
		if (m-c[i].x <= c[i].r || c[i].y <= c[i].r) {
			unin(k+2, i);
		}
	}
	for (int i = 1; i < k; i++) {
		for (int j = i+1; j <= k; j++) {
			if (dis(i, j) <= (c[i].r + c[j].r)*(c[i].r + c[j].r)) {
				unin(i, j);
			}
		}
	}
	if (find(k+1) == find(k+2)) {
		std::cout << "N\n";
	} else {
		std::cout << "S\n";
	}
	
}