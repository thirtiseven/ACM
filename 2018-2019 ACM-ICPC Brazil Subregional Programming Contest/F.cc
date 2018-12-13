#include <iostream>

const int maxn = 1234;

struct event {
	int l, r, w, s;
}e[maxn];

bool cmp (event a, event b) {
	return a.r < b.r;	
}

int dp[maxn];
ll sta[maxn];

int main(int argc, char *argv[]) {  
	int n, m;
	int cnt = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> m;
		for (int j = 0; j < m; j++) {
			std::cin >> e[cnt].l >> e[cnt].r >> e[cnt].w;
			e[cnt].s = i;
			cnt++;
		}
	}
	std::sort(e, e+cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (e[j].r <= e[i].l) {
				temp = std::max(temp, dp[j]+e[i].w);
			}
		}
	}
}