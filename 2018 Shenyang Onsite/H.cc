#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

std::ios::sync_with_stdio(false);
std::cin.tie(0);
using ll = long long;
const int maxn = 2e5+7;

std::queue<int> col;
std::
struct node {
	int pos, lr, id;
	node(int a, int b, int c) : pos(a), lr(b), id(c) {}
	const bool operator < (node &b) const {
		if (pos == b.pos) {
			return lr < b.lr;
		}
		return pos < b.pos;
	}
};
std::vector<node> itv;
int cc[maxn];
int ans;

void init() {
	itv.clear();
	col.clear();
	std::fill(cc, cc+maxn, 0);
	ans = 0;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	int l, r;
	for (int i = 1; i <= n; i++) {
		std::cin >> l >> r;
		itv.push_back(node(l, 1, i));
		itv.push_back(node(r, -1 , i));
	}
	std::sort(itv.begin(), itv.end());
	for (int i = 1; i <= k; i++) {
		col.push(i);
	}
	int now = 0;
	for (int i = 1; i <= 2*n; i++) {
		if (itv[i].lr = 1) {
			if (now == k) {
				
			} else {
				now++;
				cc[itv[i].id] = col.front();
				col.pop();
			}
		} else {
			if (cc[itv[i].id] != 0) {
				now--;
				col.push(cc[itv[i].id]);
				
			} else {
				cc[itv[i].id] = 1;
			}
		}
	}
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		init();
		solve();
	}
}