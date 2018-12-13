#include<bits/stdc++.h>
#define N 600005
#define lson (o<<1)
#define rson (o<<1|1)
#define inf 1<<30
using namespace std;
typedef long long ll;
int n;
inline int read(){
		int f=1,x=0;char ch;
		do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
		do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
		return f*x;
}
//Segment-Tree-Beats!
int maxv[N<<2],seca[N<<2],cnta[N<<2],minv[N<<2],seci[N<<2],cnti[N<<2],tagv[N<<2];
ll sumv[N<<2];
inline void pushup(int o){
	int l=o<<1,r=o<<1|1;sumv[o]=sumv[l]+sumv[r];
	if(maxv[l]==maxv[r])maxv[o]=maxv[l],cnta[o]=cnta[l]+cnta[r],seca[o]=max(seca[l],seca[r]);
	else{
		if(maxv[l]>maxv[r]) swap(l,r);maxv[o]=maxv[r]; cnta[o]=cnta[r];seca[o]=max(seca[r],maxv[l]);
	}
	if(minv[l]==minv[r])
		minv[o]=minv[l],cnti[o]=cnti[l]+cnti[r],seci[o]=min(seci[l],seci[r]);
	else{
		if(minv[l]<minv[r]) swap(l,r);minv[o]=minv[r]; cnti[o]=cnti[r];seci[o]=min(seci[r],minv[l]);
	}
}
inline void puttag(int o,int l,int r,int v){
		tagv[o]+=v;sumv[o]+=(ll)(r-l+1)*v;
		minv[o]+=v;maxv[o]+=v;seca[o]+=v;seci[o]+=v;
}
inline void tmax(int o,int l,int r,int v){
		sumv[o]+=(ll)(cnti[o])*(v-minv[o]);
		minv[o]=v;maxv[o]=max(v,maxv[o]);
		if(minv[o]==maxv[o]){
				sumv[o]=1LL*(r-l+1)*v;cnta[o]=cnti[o]=r-l+1;seca[o]=-inf;seci[o]=inf;
		}else seca[o]=max(v,seca[o]);
}
inline void tmin(int o,int l,int r,int v){
		sumv[o]-=(ll)(cnta[o])*(maxv[o]-v);
		maxv[o]=v;minv[o]=min(v,minv[o]);
		if(maxv[o]==minv[o]){
				sumv[o]=(ll)(r-l+1)*v;cnta[o]=cnti[o]=r-l+1;seca[o]=-inf;seci[o]=inf;
		}else seci[o]=min(v,seci[o]);
}
inline void pushdown(int o,int l,int r){
		int mid=(l+r)>>1;
		if(tagv[o]){
				puttag(lson,l,mid,tagv[o]);puttag(rson,mid+1,r,tagv[o]);
				tagv[o]=0;
		}
		if(maxv[lson]>maxv[o]&&seca[lson]<maxv[o])tmin(lson,l,mid,maxv[o]);
		if(maxv[rson]>maxv[o]&&seca[rson]<maxv[o])tmin(rson,mid+1,r,maxv[o]);
		if(minv[lson]<minv[o]&&seci[lson]>minv[o])tmax(lson,l,mid,minv[o]);
		if(minv[rson]<minv[o]&&seci[rson]>minv[o])tmax(rson,mid+1,r,minv[o]);
}
void build(int o,int l,int r){
		tagv[o]=0;
		if(l==r){
			sumv[o]=maxv[o]=minv[o]=0;cnta[o]=cnti[o]=1;seca[o]=-inf;seci[o]=inf;tagv[o]=0;return;
		}
		int mid=(l+r)>>1;
		build(lson,l,mid);build(rson,mid+1,r);
		pushup(o);
}
void changemax(int o,int l,int r,int ql,int qr,int v){
		if(minv[o]>=v)return;
		if(ql<=l&&r<=qr&&v<seci[o]){tmax(o,l,r,v);return;}
		pushdown(o,l,r);int mid=(l+r)>>1;
		if(ql<=mid)changemax(lson,l,mid,ql,qr,v);
		if(qr>mid)changemax(rson,mid+1,r,ql,qr,v);
		pushup(o);
}
void changemin(int o,int l,int r,int ql,int qr,int v){
		if(maxv[o]<=v)return;
		if(ql<=l&&r<=qr&&v>seca[o]){tmin(o,l,r,v);return;}
		pushdown(o,l,r);int mid=(l+r)>>1;
		if(ql<=mid)changemin(lson,l,mid,ql,qr,v);
		if(qr>mid)changemin(rson,mid+1,r,ql,qr,v);
		pushup(o);
}
void add(int o,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr){puttag(o,l,r,v);return;}
		pushdown(o,l,r);int mid=(l+r)>>1;
		if(ql<=mid)add(lson,l,mid,ql,qr,v);
		if(qr>mid)add(rson,mid+1,r,ql,qr,v);
		pushup(o);
}
int querymax(int o,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return maxv[o];
		pushdown(o,l,r);int mid=(l+r)>>1,ans=-inf;
		if(ql<=mid)ans=max(ans,querymax(lson,l,mid,ql,qr));
		if(qr>mid)ans=max(ans,querymax(rson,mid+1,r,ql,qr));
		return ans;
}
int querymin(int o,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return minv[o];
		pushdown(o,l,r);int mid=(l+r)>>1,ans=inf;
		if(ql<=mid)ans=min(ans,querymin(lson,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,querymin(rson,mid+1,r,ql,qr));
		return ans;
}
ll querysum(int o,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return sumv[o];
		pushdown(o,l,r);int mid=(l+r)>>1;ll ans=0;
		if(ql<=mid)ans+=querysum(lson,l,mid,ql,qr);
		if(qr>mid)ans+=querysum(rson,mid+1,r,ql,qr);
		return ans;
}
//End of Segment Tree
int main(){
		n=read();build(1,1,n);
		int T=read();
		while(T--){
				int opt=read(),l=read(),r=read(),v;
				if(opt==1)v=read(),add(1,1,n,l,r,v);
				if(opt==2)v=read(),changemax(1,1,n,l,r,v);
				if(opt==3)v=read(),changemin(1,1,n,l,r,v);
				if(opt==4)printf("%lld\n",querysum(1,1,n,l,r));
				if(opt==5)printf("%d\n",querymax(1,1,n,l,r));
				if(opt==6)printf("%d\n",querymin(1,1,n,l,r));
		}
}