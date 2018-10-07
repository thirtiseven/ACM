#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
map<ll,ll>p,vis;
ll num=0;
int main(int argc, char *argv[]) {  
	ll n;scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		ll t,x,y;
		scanf("%lld%lld%lld",&t,&x,&y);
		num++;

		if(t==1)
		{
					vis[x]=num;
			p[x]=y;
		}
		else if(t==2)
		{
			auto it=p.lower_bound(x);
//			cout<<it->first<<endl;
ll tmp=1e18;
			if(it!=p.end())
			tmp=(x-it->first)*(x-it->first)+(y-it->second)*(y-it->second);
//			cout<<"tmp1="<<tmp<<endl;
			if(it!=p.end()&&tmp<(it->second)*(it->second))
			{
				if(vis[it->first])
				{
					printf("%lld\n",vis[it->first]);
//					cout<<vis[it->first]<<endl;
					vis[it->first]=0;
				}
				p.erase(it);
			}
			else if(it!=p.begin())
				{
					it--;
					ll tmp=(x-it->first)*(x-it->first)+(y-it->second)*(y-it->second);
//					cout<<"tmp2="<<tmp<<endl;
					if(tmp<(it->second)*(it->second))
					{
						if(vis[it->first])
						{
							printf("%lld\n",vis[it->first]);
//							cout<<vis[it->first]<<endl;
							vis[it->first]=0;
						}
						p.erase(it);
					}
					else puts("-1");
				}
			else puts("-1");
			
		}
	}
	return 0;
}