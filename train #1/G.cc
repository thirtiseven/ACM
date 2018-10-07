#include <iostream>
#include <vector> 
#include <algorithm> 
#include <iomanip>
#include <cstring>

#define maxm 1000009
#define maxn 100009

using ll = long long;

std::vector<std::pair<ll, ll>> t[maxn];

class Kruskal { 
	struct UdEdge {
		ll u, v, w;
		UdEdge(){}
		UdEdge(ll u,ll v,ll w):u(u), v(v), w(w){}
	};
	ll N, M;
	UdEdge pool[maxm]; 
	UdEdge *E[maxm]; 
	ll P[maxn];
	ll Find(ll x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}	
	public:
	ll anss = 0;
	static bool cmp(const UdEdge *a, const UdEdge *b) {
		return a->w < b->w; 
	}
	void Clear(ll n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(ll u, ll v, ll w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = &pool[M];
		++M; 
	}
	ll Run() {
		ll i, ans=0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge *e = E[i]; 
			ll x = Find(e->u); 
			ll y = Find(e->v); 
			if(x != y) {
				t[e->u].push_back(std::make_pair(e->v, e->w));
				t[e->v].push_back(std::make_pair(e->u, e->w));
				P[y] = x;
				ans += e->w; 
			}
		}
		return ans; 
	}
	int vis[maxn];
	ll dfs(ll now) {
		vis[now] = 1;
		ll s = 0, rt = 0; 
		for (auto it: t[now]) {
			ll y = it.first;
			if(!vis[y]) {
				s = dfs(y);
				rt += s;
				anss += s*(N-s)*it.second;
			}
		}
		return rt+1LL;
	}
} aa;


int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	int T;
	ll u, v, w, n, m;
	std::cin >> T;
	while (T--) {
		memset(aa.vis, 0, sizeof(aa.vis));
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			t[i].clear();
		}
		aa.Clear(n);
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v >> w;
			aa.AddEdge(u, v, w);
		}
		ll ans = aa.Run();
		aa.dfs(1);
		if (n==1) {
			aa.anss = t[1][0].second;
			std::cout << ans << " " << aa.anss << ".00\n";
			exit(0);
		}
		std::cout << ans << " ";
		std::cout << std::fixed << std::setprecision(3) << double(aa.anss*1.0/((n-1)*n*1.0/2.0)) << '\n';
	}
}