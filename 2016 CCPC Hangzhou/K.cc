#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 303;
		
int n;
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
	int s;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		memset(g, 0, sizeof(g));
		bool yes = 1;
		std::cin >> n >> s;
		if (n > s) std::swap(s, n);
		if (n >= 300) {
			yes = 0;
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if ((s+i)%j == 0) {
						g[i-1][j-1] = 1;
					}
				}
			}
			if (hungary() != n) {
				yes = 0;
			}
		}
		std::cout << "Case #" << CAS << ": " << (yes?"Yes":"No") << '\n';
	}
}