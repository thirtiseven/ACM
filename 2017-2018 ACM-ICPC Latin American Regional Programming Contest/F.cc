#include <iostream>
#include <algorithm>
using namespace std;
#define  maxn 100005
struct node{
	int x,y,val;
	bool friend operator<(node a,node b){
		if(a.x<=b.x) return 1;
		else if(a.x==b.x&&a.y<b.y) return 1;
		else return 0;
	}
}a[maxn],ans[maxn];
int tree[maxn];
void add(int i, int x,int n) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

int binary(int i,int len){
	int left=0,right=len,mid;
	
	while(left<=right){
		mid=(left+right)>>1;
		if((ans[mid].x>a[i].x&&ans[mid].y>a[i].y&&ans[mid].val>=a[i].val)||(ans[mid].x==a[i].x&&ans[mid].y==a[i].y&&ans[mid].val>=a[mid].val)){
			right=mid-1;
		}
		else left=mid+1;
	}
	return left;
}
int main(int argc, char *argv[]) {  
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].val;
	}
	sort(a+1,a+n+1);
	ans[1]=a[1];
	add(1,a[1].val,n);
	int len=1;
	for(int i=2;i<=n;i++){
		int tmp=sum(len)+a[i].val;
		if((a[i].x>ans[len].x&&a[i].y>ans[len].y&&tmp>=ans[len].val)||(a[i].x==ans[len].x&&a[i].y==ans[len].y&&tmp>=ans[i].val)){
			ans[++len]=a[i];
			ans[len].val=tmp;
//			ans[len].val+=ans[len-1].val;
			add(len,a[i].val,n);
		}
		else{
			int tt=a[i].val;
			a[i].val=tmp;
			int pos=binary(i,len);
			ans[pos]=a[i];
			a[i].val=tt;
			add(pos,a[i].val,n);
		}
	}
	cout<<ans[len].val<<endl;
//	int Ans=0;
//	for(int i=1;i<=len;i++){
//		Ans=max(Ans,ans[i].val);
//	}
//	cout<<Ans<<endl;
}