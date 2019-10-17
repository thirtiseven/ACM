#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

const int maxn = 3e5+7;
const int mod = 998244353;
std::vector<int> t[maxn];
int n, m, T, u, v;
int twopow[maxn];
int dep[maxn], left;

template <class T>
inline bool Read(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-') ?-1:1 ;
	ret=(c=='-') ?0:(c -'0');
	while(c=getchar(),c>='0'&&c<='9')
		ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

void init() {
	twopow[0] = 1;
	for (int i = 1; i <= 300000; i++) {
		twopow[i] = (twopow[i-1] * 2) % mod;
	}
}

ll ans = 0;

void dfs(int now, int fa, int depth) {
	dep[now] = depth;
	for (auto it: t[now]) {
		if (it != fa && dep[it] < depth) {
			int x = depth-dep[it]+1;
			if (dep[it]) {
				ans *= (twopow[x]-1);
				left -= x;
				ans %= mod;
			} else {
				dfs(it, now, depth+1);
			}
		}
	}
}

int main(int argc, char *argv[]) {  
	init();
	Read(T);
	while (T--) {
		Read(n);
		Read(m);
		left = m, ans = 1;
		for (int i = 1; i <= n; i++) {
			t[i].clear();
			dep[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			Read(u);
			Read(v);
			t[u].push_back(v);
			t[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (!dep[i]) {
				dfs(i, -1, 1);
			}
		}
		ans *= twopow[left];
		ans %= mod;
		std::cout << ans << '\n';
	}
}