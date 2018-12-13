//#include <iostream>
//
//int main(int argc, char *argv[]) {  
//	
//}

#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
string s;
bool vis[100005];
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	int n = s.length();
	for(int l=1;l<n;l++){
		if(n%l==0){
			for(int i=0;i<l;i++){
				//如果在>=l的位置有解那么<l的位置一定也有解
				int pos = i;
				while (pos<n&&s[pos]=='R'){
					pos+=l;
				}
				if(pos>=n){
					vis[l]=true;
				}
			}
		}
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		if(vis[gcd(i,n)])
			ans++;
	}
	cout<<ans<<endl;
}