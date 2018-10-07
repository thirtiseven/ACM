#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100005;
struct edge{
	int s,t;
}e[maxn];
int n,m,num;
int pre[maxn],vis[maxn],used[maxn],leaf[maxn],vs[maxn],st[maxn];
vector<pair<int,int> > v[maxn];
void dfs(int u){
	int cnt = 0;
	for(int i=0;i<v[u].size();i++){
		int to = v[u][i].first, idx = v[u][i].second;
		if(vis[to]) continue;
		cnt++;
		vis[to] = 1;
		used[idx] = 1;
		pre[to] = u;
		dfs(to);
	}
	if(cnt==0)leaf[num++] = u;
}
int main(int argc, char *argv[]) {  
	scanf("%d%d", &n,&m);
	for(int i = 1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		e[i].s = a,e[i].t=b;
		v[a].push_back(make_pair(b, i));
	}
	dfs(1);
	int ans = n - 1;
	int index = 0, fa;
	while(leaf[index]){
		int ti = leaf[index];
		if(ti==1){
			index++;
			continue;
		}
		for(int i=st[ti];i<v[ti].size();i++){
			int to = v[ti][i].first, ei = v[ti][i].second;
			if(!used[ei]){
				ans++;
				fa = to;
				leaf[num++] = to;
				used[ei] = 1;
				st[ti] = i+1;
				break;
			}
		}
		int no = ti;
		while(no != fa){
			if(!vs[no]) vs[no] = 1;
			no = pre[no];
		}
		index++;
	}
	for(int i=1;i<=m;i++){
		if(used[i])continue;
		if(ans < n * 2){
			ans++;
			continue;
		}
		printf("%d %d\n", e[i].s, e[i].t);
	}
}