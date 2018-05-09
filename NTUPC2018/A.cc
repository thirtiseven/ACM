#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
const int maxn = 100000+7;
const int INF = 1e9;
int n, w, len, c[maxn];
double p[maxn], val[maxn];
struct nod {
	double t1,t2;
	bool operator <(const nod &b)const {
		return t1==b.t1?t2>b.t2:t1<b.t1;
	}
} node[maxn];

int ask(int x) {
	int ret=0;
	while(x) {
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}

void add(int x) {
	while(x<=len) {
		c[x]++;
		x+=x&-x;
	}
}

int main (int argc, char * argv[]) {
	std::cin >> n >> w;
	int x, v;
	for (int i=1; i<=n; i++) {
		std::cin >> x >> v;
		node[i] = (nod) {
			(double)(v-w)/x,(double)(v+w)/x
		};
	}
	std::sort(node+1,node+n+1);
	for (int i=1; i<=n; i++) {
		p[i]=node[i].t2;
	}
	std::sort(p+1, p+1+n);
	len = std::unique(p+1, p+n+1) - p - 1;
	for (int i=1; i<=n; i++) {
		val[i] = std::lower_bound(p+1, p+len+1, node[i].t2) - p;
	}
	long long ans=0;
	for (int i=n; i>=1; i--) {
		ans += ask(val[i]);
		add(val[i]);
	}
	std::cout << ans;
}