#include <iostream>
#include <queue> 
#include <cstring> 
#include <vector> 

const int maxn = 20007; 
const int inf = 0x7FFFFFFF; 

struct Edge { 
	int v,w;
	Edge(int v,int w):v(v),w(w){} 
};

int d[maxn];
bool inq[maxn]; 
std::vector<Edge> G[maxn];

void SPFA(int s) { 
	std::queue<int> q;
	memset(inq, 0, sizeof(inq)); 
	for(int i=0; i<maxn; ++i) {
		d[i] = inf; 
	}
	d[s] = 0;
	inq[s] = 1; 
	q.push(s);
	int u; 
	while(!q.empty()){
		u = q.front(); 
		q.pop(); 
		inq[u]=0;
		for (auto e=G[u].begin(); e != G[u].end(); ++e) {
			if (d[e->v] > d[u]+e->w) {
				d[e->v] = d[u]+e->w; 
				if (!inq[e->v]) {
					q.push(e->v);
					inq[e->v]=1; 
				}
			} 
		}
	}	
}

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= 10000; i++) {
		G[i].push_back(Edge(2*i, 1));
	}
	for(int i = 2; i <= 20000; i++) {
		G[i].push_back(Edge(i-1, 1));
	}
	SPFA(n);
	std::cout << d[m] << std::endl;
	return 0;
}