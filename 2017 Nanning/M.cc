#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 206;
int n, m;		
int g[maxn][maxn];	//0-labeled
int linker[maxn];
bool used[maxn];

bool dfs(int u) {
	int v;
	for(v = 0; v < n; v++) {
		if(g[u][v] && !used[v]) {
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}    
		} 
	}
	return false;  
}   
 
int hungary() {
	int res = 0;
	int u;
	memset(linker, -1, sizeof(linker)); 
	for(u = 0; u < n; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u)) {
			res++;
		}
	} 
	return res;   
}  

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int u, v;
		std::cin >> n >> m;
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v;
			g[u-1][v-1] = 1;
		}
		for (int i = 0; i < n; i++) {
			g[i][i] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (g[i][k] && g[k][j]) {
						g[i][j] = 1;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			g[i][i] = 0;
		}
		std::cout << n-hungary() << '\n';
	}
}