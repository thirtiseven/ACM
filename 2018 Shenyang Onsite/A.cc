#include <iostream>
#include <set>

unsigned long long k1, k2;

unsigned long long xorShift123Plus() {
	unsigned long long k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4;	
}

int n, m, u[100001], v[100001];
unsigned long long w[100001];

void gen() {
	scanf("%d%d%llu%llu", &n, &m, &k1, &k2);
	for (int i = 1; i <= m; ++i) {
		u[i] = xorShift123Plus() % n + 1;
		v[i] = xorShift123Plus() % n + 1;
		w[i] = xorShift123Plus();
	}
}

const unsigned long long mod = 1e9+7;

#include <vector> 
#include <algorithm> 

using ll = unsigned long long;
const int maxn = 100001;
const int maxm = 100001;

class Kruskal { 
	struct UdEdge {
		int u, v;
		ll w;
		UdEdge(){}
		UdEdge(int u,int v,ll w):u(u), v(v), w(w){}
	};
	int N, M;
	UdEdge pool[maxm]; 
	UdEdge *E[maxm]; 
	int P[maxn];
	int Find(int x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}	
	public:
	static bool cmp(const UdEdge *a, const UdEdge *b) {
		return a->w < b->w; 
	}
	void Clear(int n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(int u, int v, ll w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = &pool[M];
		++M; 
	}
	ll Run() {
		int i;
		ll ans = 0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge *e = E[i]; 
			int x = Find(e->u); 
			int y = Find(e->v); 
			if(x != y) {
				P[y] = x;
				ans += e->w; 
				ans %= mod;
			}
		}
		return ans; 
	}
};

int main(int argc, char *argv[]) {  
	int T;
	scanf("%d", &T);
	Kruskal ac;
	std::set<int> exist;
	while (T--) {
		gen();
		exist.clear();
		for (int i = 1; i <= m; i++) {
			exist.insert(u[i]);
			exist.insert(v[i]);
		}
		if (exist.size() != n) {
			printf("0\n");
			continue;
		}
		ac.Clear(n);
		for (int i = 1; i <= m; i++) {
			ac.AddEdge(u[i], v[i], w[i]);
		}
		printf("%llu\n", ac.Run());
	}
}