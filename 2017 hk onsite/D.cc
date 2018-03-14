#include <iostream>
#include <vector> 
#include <queue>
#include <cstring>
#define INF 0x7FFFFFFF 
#define maxn 1000 

class Dijkstra{ 
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
		for(i=0;i<n;++i) 
			G[i].clear(); 
		for(i=0;i<n;++i) 
			d[i] = INF;
		memset(vis, 0, sizeof(vis)); 
	}
	void AddEdge(int u, int v, int w){ 
		G[u].push_back(Edge(v, w));
	}
	void Run(int s){ 
		int u;
		std::priority_queue<HeapNode> q;
		d[s] = 0; 
		q.push(HeapNode(s, 0)); 
		while (!q.empty()){
			u = q.top().u;
			q.pop();
			if (!vis[u]){
				vis[u] = 1;
				for (std::vector<Edge>::iterator e = G[u].begin(); e != G[u].end(); ++e) {
					if (d[e->v] > d[u] + e->w){ 
						d[e->v] = d[u] + e->w;
						q.push(HeapNode(e->v, d[e->v])); 
					}
				}
			}
		}
	}
};

int main(int argc, char *argv[]) {  
	int m;
	while (std::cin >> m) {
		Dijkstra dij;
		dij.clear(m+1);
		int from, to;
		int tu, tv, tw;
		std::cin >> from >> to;
		while(std::cin >> tu) {
			if(!tu) {
				break;
			}
			std::cin >> tv >> tw;
			dij.AddEdge(tu, tv, tw);
			dij.AddEdge(tv, tu, tw);
		}
		dij.Run(from);
		std::cout << dij.d[to] << '\n';
	}
	return 0;
}