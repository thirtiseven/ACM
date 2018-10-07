#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 1005
int vis[maxn],a[maxn];
vector<int>v;
int main(int argc, char *argv[]) {  
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
		{
			vis[a[i]]++;
		}
		else
		{
			if(vis[abs(a[i])])
			{
				vis[abs(a[i])]--;
			}
			else if(vis[0])
			{
				vis[0]--;
				v.push_back(abs(a[i]));
			}
			else
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(auto it:v) cout<<it<<' ';
	cout<<endl;
}