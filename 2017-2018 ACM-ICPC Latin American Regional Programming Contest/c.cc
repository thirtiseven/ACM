#include <iostream>
using namespace std;
#define  maxn 10005
int vis[maxn], cnt[maxn];
int main(int argc, char *argv[]) {  
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vis[x]++;
	}
	int mi = 100000, ma = -1, miv, mav;
	for(int i=1;i<=k;i++){
		cnt[vis[i]]++;
		if(mi > vis[i]){
			mi=vis[i];
			miv=i;
		}
		if(ma < vis[i]){
			ma=vis[i];
			mav=i;
		}
	}
	//cout<<mi<<" "<<cnt[mi]<<" "<<ma<<" "<<cnt[ma];
	if(mi+1==ma){
		if(cnt[mi]==1){if(cnt[ma]!=1) cout<<"+"<<miv<<endl;}
		else if(cnt[ma]==1){if(cnt[mi]!=1) cout<<"-"<<mav<<endl;}
		else cout<<"*"<<endl;
	}
	else if(ma == mi + 2){
		if(cnt[mi]==1 && cnt[ma]==1){
			cout<<"-"<<mav<<" +"<<miv<<endl;
		}
		else cout<<"*"<<endl;
	}
	else cout<<"*"<<endl;
}