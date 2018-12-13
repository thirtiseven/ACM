#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>
#define INF 0x7FFFFFFF 

const int maxn = 2e6;

class Dijkstra { 
private:
	struct HeapNode{ 
		int u;
		int d;
		HeapNode(int u, int d) :u(u), d(d){}
		bool operator < (const HeapNode &b) const{
			return d > b.d; 
		}
	};
	struct Edge{ 
		int v;
		int w; 
		Edge(int v, int w) :v(v), w(w){}
	}; 
	std::vector<Edge>G[maxn];
	bool vis[maxn];
public:
	int d[maxn];
	void clear(int n){
		int i;
		for(i=0;i<n;++i) G[i].clear(); 
		for(i=0;i<n;++i) d[i] = INF;
	}
	void AddEdge(int u, int v, int w){ 
		G[u].push_back(Edge(v, w));
	}
	void Run(int s){ 
		memset(vis, 0, sizeof(vis));
		int u;
		std::priority_queue<HeapNode> q;
		d[s] = 0; 
		q.push(HeapNode(s, 0)); 
		while (!q.empty()){
			u = q.top().u;
			q.pop();
			if (!vis[u]){
				vis[u] = 1;
				for (std::vector<Edge>::iterator e = G[u].begin(); e != G[u].end(); ++e)
					if (d[e->v] > d[u] + e->w){ 
						d[e->v] = d[u] + e->w;
						q.push(HeapNode(e->v, d[e->v])); 
					}
			}
		}
	}
};

Dijkstra az;
int ans[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		int n, m;
		std::cin >> n >> m;
		az.clear(n+m+1);
		int e, s, u;
		for (int i = 1; i <= m; i++) {
			std::cin >> e >> s;
			for (int j = 0; j < s; j++) {
				std::cin >> u;
				az.AddEdge(u, n+i, e);
				az.AddEdge(n+i, u, 0);
			}
		}
		az.Run(1);
		az.Run2(n);
		int anss = INF;
		for (int i = 1; i <= n; i++) {
			ans[i] = std::max(az.d[i], az.d2[i]);
			anss = std::min(anss, ans[i]);
		}
		if (anss == INF) {
			std::cout << "Case #" << ca << ": Evil John\n";
		} else {
			std::vector<int> pos;
			for (int i = 1; i <= n; i++) {
				if (ans[i] == anss) {
					pos.push_back(i);
				}
			}
			std::sort(pos.begin(), pos.end());
			std::cout << "Case #" << ca << ": " << anss << '\n';
			std::cout << pos[0];
			for (int i = 1; i < pos.size(); i++) {
				std::cout << " " << pos[i];
			}
			std::cout << "\n";
		}
	}
}