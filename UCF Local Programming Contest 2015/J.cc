#include <iostream>
#include <queue> 
#include <vector> 
#include <cstring> 
#include <algorithm>
#include <iomanip>
#include <cmath>

const int maxn = 50+2+2*50*50+7;
const int inf = 0x3f3f3f3f; 

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
}F;

int T, n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		F.Init(n*n*2+n+2);
		double temp;
		int temp100;
		int s = 0, t = n+n*n*2+1, sum = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> temp;
			temp100 = round(100*temp);
			sum += temp100;
			F.AddEdge(s, i, temp100);
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> temp;
			temp100 = round(100*temp);
			sum += temp100;
			F.AddEdge(i, t, temp100);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> temp;
				temp100 = round(100*temp);
				sum += temp100;
				sum += temp100;
				F.AddEdge(s, n+n*i+j, temp100);
				F.AddEdge(n+n*i+j, i+1, inf);
				F.AddEdge(n+n*i+j, j, inf);
				F.AddEdge(n+n*n+n*i+j, t, temp100);
				F.AddEdge(i+1, n+n*n+n*i+j, inf);
				F.AddEdge(j, n+n*n+n*i+j, inf);
			}
		}
		std::cout << std::fixed << std::setprecision(2) << (sum-F.MaxFlow(s, t))/100.0 << '\n';
	}
}