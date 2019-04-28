#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using ull = unsigned long long;
const ull maxn = 4003;
const ll INF = 100000000;
const ll big = 100000000;

struct Edge { 
	ll from, to, cap, flow;
	Edge(ll from, ll to, ll cap, ll flow) : from(from), to(to), cap(cap), flow(flow){} 
};

struct ISAP {
	ll n, m, s, t;      //结点数，边数（包括反向弧），源点编号和汇点编号
	vector<Edge> edges;  //边表。edges[e]和edges[e^1]互为反向弧
	vector<ll> G[maxn]; //邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
	bool vis[maxn];      //BFS使用
	ll d[maxn];         //起点到i的距离
	ll cur[maxn];       //当前弧下标
	ll p[maxn];         //可增广路上的一条弧
	ll num[maxn];       //距离标号计数
	void init(ll n) {
		this->n = n;
		for (ll i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(ll from, ll to, ll cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		ll m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	ll Augumemt() {
		ll x = t, a = INF;
		while (x != s) {
			Edge& e = edges[p[x]];
			a = min(a, e.cap - e.flow);
			x = edges[p[x]].from;
		}
		x = t;
		while (x != s) {
			edges[p[x]].flow += a;
			edges[p[x] ^ 1].flow -= a;
			x = edges[p[x]].from;
		}
		return a;
	}
	void BFS() {
		memset(vis, 0, sizeof(vis));
		memset(d, 0, sizeof(d));
		queue<ll> q;
		q.push(t);
		d[t] = 0;
		vis[t] = 1;
		while (!q.empty()) {
			ll x = q.front();
			q.pop();
			ll len = G[x].size();
			for (ll i = 0; i < len; i++) {
				Edge& e = edges[G[x][i]];
				if (!vis[e.from] && e.cap > e.flow) {
					vis[e.from] = 1;
					d[e.from] = d[x] + 1;
					q.push(e.from);
				}
			}
		}
	}
	ll Maxflow(ll s, ll t) {
		this->s = s;
		this->t = t;
		ll flow = 0;
		BFS();
		memset(num, 0, sizeof(num));
		for (ll i = 0; i < n; i++)
			if (d[i] < INF) num[d[i]]++;
		ll x = s;
		memset(cur, 0, sizeof(cur));
		while (d[s] < n) {
			if (x == t) {
				flow += Augumemt();
				x = s;
			}
			ll ok = 0;
			for (ll i = cur[x]; i < G[x].size(); i++) {
				Edge& e = edges[G[x][i]];
				if (e.cap > e.flow && d[x] == d[e.to] + 1) {
					ok = 1;
					p[e.to] = G[x][i];
					cur[x] = i;
					x = e.to;
					break;
				}
			}
			if (!ok) {//Retreat
				ll m = n - 1;
				for (ll i = 0; i < G[x].size(); i++) {
					Edge& e = edges[G[x][i]];
					if (e.cap > e.flow) m = min(m, d[e.to]);
				}
				if (--num[d[x]] == 0) break; //gap优化
				num[d[x] = m + 1]++;
				cur[x] = 0;
				if (x != s) x = edges[p[x]].from;
			}
		}
		return flow;
	}
}gao;

ll n, m, c;
std::string grid[33];
ll cost[30];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> c;
	gao.init(4002);
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
				gao.AddEdge(i*31+j+gugu, 4000, big);
			}
			if (j > 0) {
				gao.AddEdge(i*31+j+gugu, i*31+j-1LL, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 4000, big);
			}
			if (i < n-1LL) {
				gao.AddEdge(i*31+j+gugu, (i+1LL)*31+j, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 4000, big);
			}
			if (j < m-1LL) {
				gao.AddEdge(i*31+j+gugu, i*31+j+1LL, big);
			} else {
				gao.AddEdge(i*31+j+gugu, 4000, big);
			}
		}
	}
	ll ans = gao.Maxflow(start, 4000);
	if (ans >= big || ans == 0) {
		ans = -1;
	}
	std::cout << ans;
}