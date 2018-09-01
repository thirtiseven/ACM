#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

const int mod = 19960308;
int f[1000007];
int c[100005];
int n,m;

int lowbit(int x) {
	return x&(-x);
}

void add(int pos,int x) {
	while(pos<=n) {
		c[pos]+=x;
		pos+=lowbit(pos);
	}
}

int query(int pos) {
	int res=0;
	while(pos>0)
	{
		res+=c[pos];
		pos-=lowbit(pos);
	}
	return res;
} 

int main(int argc, char *argv[]) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 1e6; i++) {
		f[i] = (f[i-1]+f[i-2])%mod;
	}
	scanf("%d%d",&n,&m);
	int x=0,y;
	for(int i=1;i<=n;i++) {
		add(i,0);
	}
	int opt,k;
	for(int i=1;i<=m;i++) {
		scanf("%d",&opt);
		if(opt==1) {
			scanf("%d%d%d",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		} else if(opt==2) {
			scanf("%d",&x);
			printf("%d\n",f[query(x)]);
		}
	}
	return 0;
 } 