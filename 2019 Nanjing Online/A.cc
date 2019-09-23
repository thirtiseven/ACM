#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using ll = int;

const ll maxn = 4e5+7;
const ll maxw = 4e6+8;
#define lowbit(x) (x&-x)

struct query {
	ll type,id,x,y,k,ans; //0修改，1查询
	ll operator <(const query& rhs) const {
		return id<rhs.id;
	}
} q[maxn],t[maxn];

ll W;
ll c[maxw];

inline void add(ll x,ll y) { 
	while (x<=W) 
		c[x]+=y,x+=lowbit(x); 
}

inline ll sum(ll x) { 
	ll rt=0; 
	while (x) rt+=c[x],x^=lowbit(x); 
	return rt; 
}

inline void clear(ll x) { 
	while (x<=W) 
		c[x]=0,x+=lowbit(x); 
}

ll ans[maxn];

inline void CDQ(ll L,ll R) {
	if (L==R) return;
	ll mid=(L+R)>>1;
	CDQ(L,mid),CDQ(mid+1,R);
	ll i=L,j=mid+1,k=L;
	while (i<=mid&&j<=R) {
		if (q[i].x<=q[j].x) {
			if (!q[i].type) add(q[i].y,q[i].k);
			t[k++]=q[i++];
		} else {
			if (q[j].type) q[j].ans+=sum(q[j].y);
			t[k++]=q[j++];
		}
	}
	while (i<=mid) {
		if (!q[i].type) add(q[i].y,q[i].k);
		t[k++]=q[i++];
	}
	while (j<=R) {
		if (q[j].type) q[j].ans+=sum(q[j].y);
		t[k++]=q[j++];
	}
	for (ll p=L;p<=mid;++p)
		if (!q[p].type) clear(q[p].y);
	for (ll p=L;p<=R;++p) q[p]=t[p];
}

int gao(ll x, ll y) {
	ll r = 0, t = W+1-y, a = W+1-x, res;
	if (a<=t && (a+t <= W+1)) {   
		r = a;
		res = 4*(r-1)*W - 4*(r-1)*(r-1) +1 + t-r;
	} else if (a<=t && (a+t >= W+1)) {   
		r = W - t + 1;
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + W-2*r + 1 + a - r;
	} else if (a>=t && (a+t >= W+1)) {   
		r = W - a +1;
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + 3*W-6*r + 3 - t + r;
	} else if (a >=t && (a+t <= W+1)) {   
		r = t;   
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + 4*W-8*r + 4  - a + r;
	}
	ll ans = 0;
	while (res) {
		ans += res%10;
		res /= 10;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		ll tot=0;
		ll m, p;
		std::cin >> W >> m >> p;
		int x, y, k;
		for (ll i = 0; i < m; i++) {
			std::cin >> x >> y;
			++tot;
			q[tot]=(query){0,tot,x,y,gao(x,y),0};
		}
		int lx, ly, rx, ry;
		for (ll i = 0; i < p; i++) {
			std::cin >> lx >> ly >> rx >> ry;
			++tot;
			q[tot]=(query){1,tot,rx,ry,0,0};
			++tot;
			q[tot]=(query){1,tot,rx,ly-1,0,0};
			++tot;
			q[tot]=(query){1,tot,lx-1,ry,0,0};
			++tot;
			q[tot]=(query){1,tot,lx-1,ly-1,0,0};
		}
		CDQ(1,tot); 
		std::sort(q+1,q+tot+1);
		for (ll i=1;i<=tot;++i) {
			if (q[i].type) {
				std::cout << q[i].ans-q[i+1].ans-q[i+2].ans+q[i+3].ans << '\n';
				i+=3;
			}
		}
	}
}