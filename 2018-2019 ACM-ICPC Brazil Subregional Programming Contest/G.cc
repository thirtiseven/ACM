#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#include <algorithm>

const int maxn = 2024;
const int maxm = 20009;
const int inf = 0x7FFFFFFF; 

struct Edge { 
	int c, f;
	unsigned v, flip;
	Edge(unsigned v, int c, int f, unsigned flip) : v(v), c(c), f(f), flip(flip) {} 
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
	int a[maxn];
	unsigned p[maxn], cur[maxn], d[maxn];
	std::vector<Edge> G[maxn];
public:
	unsigned s, t;
	void Init(unsigned n) { 
		for(int i=0; i<=n; ++i)
			G[i].clear();
	}
	void AddEdge(unsigned u, unsigned v, int c) { 
		G[u].push_back(Edge(v, c, 0, G[v].size())); 
		G[v].push_back(Edge(u, 0, 0, G[u].size()-1)); //使用无向图时将0改为c即可
	}
	bool BFS() { 
		unsigned u, v;
		std::queue<unsigned> q; 
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
					d[e.v] = d[u] + 1; 
					q.push(e.v);
				} 
			}
		}
		return b[t]; 
	}
	int DFS(unsigned u, int a){ 
		if(u==t || a==0)
			return a; 
		int flow = 0, f;
		for (unsigned &i = cur[u]; i<G[u].size(); ++i){ 
			Edge &e = G[u][i];
			if (d[u]+1 == d[e.v] && (f = DFS(e.v, std::min(a, e.c - e.f))) > 0) { 
				a -= f;
				e.f += f; 
				G[e.v][e.flip].f -= f; 
				flow += f;
				if (!a) break;
			} 
		}
		return flow; 
	}
	int MaxFlow(unsigned s, unsigned t){ 
		int flow = 0;
		this->s = s; 
		this->t = t; 
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, inf); 
		}
		return flow; 
	}
};

struct new_edge{
	unsigned from, to;
	int cost;
}ee[maxm];

bool cmp(new_edge a, new_edge b) {
	return a.cost < b.cost;
}

unsigned pp[maxn], rr[maxn];
Dinic D;
unsigned u, v, w;
int p, r, c;
int fill = 0;

bool check(int mid) {
	D.Init(p+r+3);
	for (int i = 0; i < r; i++) {
		D.AddEdge(0, i+1, rr[i]);
	}
	for (int i = 0; i < p; i++) {
		D.AddEdge(i+r+1, p+r+1, pp[i]);
	}
	for (int i = 0; i < mid; i++) {
		D.AddEdge(ee[i].from, ee[i].to+r, 1e9);
	}
	int max_flow = D.MaxFlow(0, p+r+1);
//	std::cout << mid << " " << max_flow << " " << fill << '\n';
	if (max_flow == fill) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> p >> r >> c;
	for (int i = 0; i < p; i++) {
		std::cin >> pp[i];
		fill+=pp[i];
	}
	for (int i = 0; i < r; i++) {
		std::cin >> rr[i];
	}
	for (int i = 0; i < c; i++) {
		std::cin >> ee[i].to >> ee[i].from >> ee[i].cost;
	}
	std::sort(ee, ee+c, cmp);
	int l = 1, r = c, mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	if (!check(c)) {
		std::cout << "-1\n";
	} else {
		std::cout << ee[l-1].cost << '\n';
	}
}