#include <iostream>
#include <vector>
#include <cmath>

const int maxn = 1024;

using ll = long long;

ll n, m;
ll k;

struct round{
	ll x, y, r;
} c[maxn];

ll fa[maxn];

void init(ll xx) {
	for (ll i = 1; i <= xx; i++) fa[i] = i;
}

ll find(ll u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(ll u, ll v) {
	fa[find(v)] = find(u);
}

ll dis(ll a, ll b) {
	return std::abs(c[a].x-c[b].x)*std::abs(c[a].x-c[b].x)+std::abs(c[a].y-c[b].y)*std::abs(c[a].y-c[b].y);
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> k;
	init(k+3);
	for (ll i = 1; i <= k; i++) {
		std::cin >> c[i].x >> c[i].y >> c[i].r;
		if (c[i].x < c[i].r || n-c[i].y < c[i].r) {
			unin(k+1, i);
		}
		if (m-c[i].x < c[i].r || c[i].y < c[i].r) {
			unin(i, k+2);
		}
	}
	for (ll i = 1; i <= k; i++) {
		for (ll j = 1; j <= k; j++) {
			if (i != j) {
				if (dis(i, j) < (c[i].r + c[j].r)*(c[i].r + c[j].r)) {
					unin(i, j);
				}
			}
		}
	}
	if (find(k+1) == find(k+2)) {
		std::cout << "N\n";
	} else {
		std::cout << "S\n";
	}
	
}