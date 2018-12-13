#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
const int maxn = 100005;
struct node {
	int l, r;
	node() {}
	node(int l, int r) :l(l), r(r) {}
	bool operator < (const node nod) const {
		return l < nod.l || (l == nod.l && r > nod.r);
	}
};
int vis[maxn], a[maxn];
node no[maxn];
int main()
{
	int T, n, m, x, y;
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			no[i].l = x, no[i].r = y;
		}
		sort(no, no + m);
		//for (int i = 0; i < m; i++)
		//	cout << no[i].l << " " << no[i].r << endl;
		//puts("--------------------");
		int r = -1;
		for (int i = 0; i < m; i++) {
			if (no[i].r <= r) vis[i] = 1;
			else r = no[i].r;
		}
		//for (int i = 0; i < m; i++) cout << vis[i] << " "; cout << endl;
		int tm = m, idx = 0;
		for (int i = 0; i < m; i++) {
			if (!vis[i]) {
				no[idx].l = no[i].l;
				no[idx++].r = no[i].r;
				//cout << i << " " << tm << endl;
			}
			else tm--;
		}
		//for (int i = 0; i < tm; i++)
		//	cout << no[i].l << " " << no[i].r << endl;
		//puts("--------------------");
		for (int i = 1; i <= n; i++) pq.push(i);
		int tl = no[0].l, tr = no[0].r;
		while (tl <= tr) { a[tl++] = pq.top(); pq.pop(); }
		for (int i = 1; i < tm; i++) {
			//if (vis[i]) continue;
			int l = no[i].l, r = no[i].r, ll = no[i - 1].l, rr = no[i - 1].r;
			for (int j = ll; j < l; j++) pq.push(a[j]);
			rr = max(rr + 1, l);
			while (rr <= r) { a[rr++] = pq.top(); pq.pop(); }
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", a[i] ? a[i] : 1, i == n ? '\n' : ' ');
	}	
	return 0;
}