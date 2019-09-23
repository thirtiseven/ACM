#include <iostream>
#include <queue> 
#include <cstring> 
#include <vector> 
#include <algorithm>

using ll = long long;

const int maxn = 507;
const ll inf = 1e9;

struct Edge{ 
	ll v;
	ll w;
	Edge(ll v,ll w):v(v),w(w){} 
};

ll d[maxn];
bool inq[maxn]; 
std::vector<Edge> G[maxn];

void SPFA(int s){ 
	std::queue<int> q;
	std::fill(inq, inq+maxn, 0); 
	for(int i=0;i<maxn;++i)
		d[i]=inf; 
	d[s]=0;
	inq[s]=1; 
	q.push(s);
	int u; 
	while(!q.empty()){
		u=q.front(); 
		q.pop(); 
		inq[u]=0;
		for(std::vector<Edge>::iterator e=G[u].begin();e!=G[u].end();++e) {
			if(d[e->v]>d[u]+e->w){
				d[e->v]=d[u]+e->w; 
				if(!inq[e->v]){
					q.push(e->v);
					inq[e->v]=1; 
				}
			} 
    	}
	}	
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T, n, m;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			G[i].clear();
		}
		for (int i = 0; i < m; i++) {
			ll u, v, w;
			std::cin >> u >> v >> w;
			G[u].push_back(Edge(v, w));
		}
		for (int i = 0; i < 6; i++) {
			ll s, t;
			std::cin >> s >> t;
			SPFA(t);
			std::cout << -d[s] << '\n';
			G[s].push_back(Edge(t, -d[s]));
		}
	}
}