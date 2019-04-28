#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#include <algorithm>
#include <string>

using ll = long long;

const ll maxn = 2003;
const ll big = 100000*30*30*10000ll;

struct Edge { 
	ll c, f;
	unsigned long long v, flip;
	Edge(unsigned long long v, ll c, ll f, unsigned long long flip) : v(v), c(c), f(f), flip(flip) {} 
};

/*
*b:BFS使用 ，
*a:可改进量 ， 不会出现负数可改进量。
*p[v]:u到v的反向边，即v到u的边。*cur[u]:i开始搜索的位置 ，此位置前所有路已满载。*s:源点。
*t:汇点 。
*/

class Dinic { 
private:
	bool b[maxn];
	ll a[maxn];
	unsigned long long p[maxn], cur[maxn], d[maxn];
	std::vector<Edge> G[maxn];
public:
	unsigned long long s, t;
	void Init(unsigned long long n) { 
		for(ll i=0; i<=n; ++i)
			G[i].clear();
	}
	void AddEdge(unsigned long long u, unsigned long long v, ll c) { 
		G[u].push_back(Edge(v, c, 0, G[v].size())); 
		G[v].push_back(Edge(u, 0, 0, G[u].size()-1)); //使用无向图时将0改为c即可
	}
	bool BFS() { 
		unsigned long long u, v;
		std::queue<unsigned long long> q; 
		memset(b, 0, sizeof(b)); 
		q.push(s);
		d[s] = 0;
		b[s] = 1; 
		while (!q.empty()) {
			u = q.front();
			q.pop();
			for (auto it = G[u].begin(); it != G[u].end(); ++it) {
				Edge &e = *it; 
				if(!b[e.v] && e.c > e.f){
					b[e.v] = 1; 
					d[e.v] = d[u] + 1LL; 
					q.push(e.v);
				} 
			}
		}
		return b[t]; 
	}
	ll DFS(unsigned long long u, ll a){ 
		if(u==t || a==0)
			return a; 
		ll flow = 0, f;
		for (unsigned long long &i = cur[u]; i<G[u].size(); ++i){ 
			Edge &e = G[u][i];
			if (d[u]+1LL == d[e.v] && (f = DFS(e.v, std::min(a, e.c - e.f))) > 0) { 
				a -= f;
				e.f += f; 
				G[e.v][e.flip].f -= f; 
				flow += f;
				if (!a) break;
			} 
		}
		return flow; 
	}
	ll MaxFlow(unsigned long long s, unsigned long long t){ 
		ll flow = 0;
		this->s = s; 
		this->t = t; 
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			ll ans = DFS(s, big);
			if (ans == big) {
				return -1;
			}
			flow += ans; 
		}
		return flow; 
	}
};

Dinic gao;
ll n, m, c;
std::string grid[33];
ll cost[30];

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> m >> n >> c;
	gao.Init(2001);
	for (ll i = 0; i < n; i++) {
		std::cin >> grid[i];
	}
	for (ll i = 0; i < c; i++) {
		std::cin >> cost[i];
	}
	ll gugu = 31*31+1;
	ll start = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll costt;
			if (grid[i][j] == 'B') {
				start = i*31+j;
				costt = big;
			} else if (grid[i][j] == '.') {
				costt = big;
			} else {
				costt = cost[ll(grid[i][j]-'a')];
			}
			gao.AddEdge(i*31+j, i*31+j+gugu, costt);
			if (i > 0) {
				gao.AddEdge(i*31+j+gugu, (i-1LL)*31+j, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 2000, big);
			}
			if (j > 0) {
				gao.AddEdge(i*31+j+gugu, i*31+j-1LL, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 2000, big);
			}
			if (i < n-1LL) {
				gao.AddEdge(i*31+j+gugu, (i+1LL)*31+j, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 2000, big);
			}
			if (j < m-1LL) {
				gao.AddEdge(i*31+j+gugu, i*31+j+1LL, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 2000, big);
			}
		}
	}
	std::cout << gao.MaxFlow(start, 2000);
}