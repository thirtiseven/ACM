//It is made by M_sea
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define re register
typedef int mainint;
#define int long long
using namespace std;

inline int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int MAXN=200000+10;
const int MAXW=2000000+10;

struct query {
	int type,id,x,y,k,ans; //0修改，1查询
	int operator <(const query& rhs) const {
		return id<rhs.id;
	}
} q[MAXN],t[MAXN];

int W;
int c[MAXW];
#define lowbit(x) (x&-x)
inline void add(int x,int y) { while (x<=W) c[x]+=y,x+=lowbit(x); }
inline int sum(int x) { int rt=0; while (x) rt+=c[x],x^=lowbit(x); return rt; }
inline void clear(int x) { while (x<=W) c[x]=0,x+=lowbit(x); }

int ans[MAXN];

inline void CDQ(int L,int R) {
	if (L==R) return;
	int mid=(L+R)>>1;
	CDQ(L,mid),CDQ(mid+1,R);
	int i=L,j=mid+1,k=L;
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
	for (re int p=L;p<=mid;++p)
		if (!q[p].type) clear(q[p].y);
	for (re int p=L;p<=R;++p) q[p]=t[p];
}

mainint main() {
	int op=read(),tot=0; W=read();
	while (1) {
		op=read(); if (op==3) break;
		if (op==1) {
			int x=read(),y=read(),k=read();
			q[++tot]=(query){0,tot,x,y,k,0};
		}
		else if (op==2) {
			int lx=read(),ly=read(),rx=read(),ry=read();
			q[++tot]=(query){1,tot,rx,ry,0,0};
			q[++tot]=(query){1,tot,rx,ly-1,0,0};
			q[++tot]=(query){1,tot,lx-1,ry,0,0};
			q[++tot]=(query){1,tot,lx-1,ly-1,0,0};
		}
	}
	CDQ(1,tot); sort(q+1,q+tot+1);
	for (re int i=1;i<=tot;++i) {
		if (q[i].type) {
			printf("%lld\n",q[i].ans-q[i+1].ans-q[i+2].ans+q[i+3].ans);
			i+=3;
		}
	}
	return 0;
}