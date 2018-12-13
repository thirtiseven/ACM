#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

const int maxm = 21;
const int maxn = maxm*maxm*2;

int n, m;		
int g[maxn][maxn];	//0-labeled
int linker[maxn];
bool used[maxn];
std::string mp[23];

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
	std::fill(linker, linker+maxn, -1);
	for(u = 0; u < n; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u)) {
			res++;
		}
	} 
	return res;   
}

int w, h;

inline int idx(int x, int y, int type) {
	return x * w * 2 + y * 2 + type;
}

int main(int argc, char *argv[]) {  
	int cnt = 0;
	std::cin >> h >> w;
	for (int i = 0; i < h; i++) {
		std::cin >> mp[i];
	}
	memset(g, 0, sizeof g);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mp[i][j] == 'o') {
				cnt++;
				if (i != 0) {
					g[idx(i, j, 0)][idx(i-1, j, 0)] = 1;
					g[idx(i-1, j, 0)][idx(i, j, 0)] = 1;
					if (mp[i-1][j] != 'o') {
						g[idx(i, j, 0)][idx(i-1, j, 1)] = 1;
						g[idx(i-1, j, 1)][idx(i, j, 0)] = 1;
					}
				}
				if (i != h-1) {
					g[idx(i, j, 0)][idx(i+1, j, 0)] = 1;
					g[idx(i+1, j, 0)][idx(i, j, 0)] = 1;
					if (mp[i+1][j] != 'o') {
						g[idx(i, j, 0)][idx(i+1, j, 1)] = 1;
						g[idx(i+1, j, 1)][idx(i, j, 0)] = 1;
					}
				}
				if (j != 0) {
					g[idx(i, j, 0)][idx(i, j-1, 0)] = 1;
					g[idx(i, j-1, 0)][idx(i, j, 0)] = 1;
					if (mp[i][j-1] != 'o') {
						g[idx(i, j, 0)][idx(i, j-1, 1)] = 1;
						g[idx(i, j-1, 1)][idx(i, j, 0)] = 1;
					}
				}
				if (j != w-1) {
					g[idx(i, j, 0)][idx(i, j+1, 0)] = 1;
					g[idx(i, j+1, 0)][idx(i, j, 0)] = 1;
					if (mp[i][j+1] != 'o') {
						g[idx(i, j, 0)][idx(i, j+1, 1)] = 1;
						g[idx(i, j+1, 1)][idx(i, j, 0)] = 1;
					}
				}
			} else {
				if (i != 0) {
					g[idx(i, j, 0)][idx(i-1, j, 0)] = 1;
					g[idx(i-1, j, 0)][idx(i, j, 0)] = 1;
					g[idx(i, j, 1)][idx(i-1, j, 0)] = 1;
					g[idx(i-1, j, 0)][idx(i, j, 1)] = 1;
					if (mp[i-1][j] != 'o') {
						g[idx(i, j, 0)][idx(i-1, j, 1)] = 1;
						g[idx(i-1, j, 1)][idx(i, j, 0)] = 1;
						g[idx(i, j, 1)][idx(i-1, j, 1)] = 1;
						g[idx(i-1, j, 1)][idx(i, j, 1)] = 1;
					}
				}
				if (i != h-1) {
					g[idx(i, j, 0)][idx(i+1, j, 0)] = 1;
					g[idx(i+1, j, 0)][idx(i, j, 0)] = 1;
					g[idx(i, j, 1)][idx(i+1, j, 0)] = 1;
					g[idx(i+1, j, 0)][idx(i, j, 1)] = 1;
					if (mp[i+1][j] != 'o') {
						g[idx(i, j, 0)][idx(i+1, j, 1)] = 1;
						g[idx(i+1, j, 1)][idx(i, j, 0)] = 1;
						g[idx(i, j, 1)][idx(i+1, j, 1)] = 1;
						g[idx(i+1, j, 1)][idx(i, j, 1)] = 1;
					}
				}
				if (j != 0) {
					g[idx(i, j, 0)][idx(i, j-1, 0)] = 1;
					g[idx(i, j-1, 0)][idx(i, j, 0)] = 1;
					g[idx(i, j, 1)][idx(i, j-1, 0)] = 1;
					g[idx(i, j-1, 0)][idx(i, j, 1)] = 1;
					if (mp[i][j-1] != 'o') {
						g[idx(i, j, 0)][idx(i, j-1, 1)] = 1;
						g[idx(i, j-1, 1)][idx(i, j, 0)] = 1;
						g[idx(i, j, 1)][idx(i, j-1, 1)] = 1;
						g[idx(i, j-1, 1)][idx(i, j, 1)] = 1;
					}
				}
				if (j != w-1) {
					g[idx(i, j, 0)][idx(i, j+1, 0)] = 1;
					g[idx(i, j+1, 0)][idx(i, j, 0)] = 1;
					g[idx(i, j, 1)][idx(i, j+1, 0)] = 1;
					g[idx(i, j+1, 0)][idx(i, j, 1)] = 1;
					if (mp[i][j+1] != 'o') {
						g[idx(i, j, 0)][idx(i, j+1, 1)] = 1;
						g[idx(i, j+1, 1)][idx(i, j, 0)] = 1;
						g[idx(i, j, 1)][idx(i, j+1, 1)] = 1;
						g[idx(i, j+1, 1)][idx(i, j, 1)] = 1;
					}
				}
			}
		}
	}
	bool yes = 1;
	n = w*h*2;
	int ans = hungary();
	ans /= 2;
	if (cnt % 2) yes = 0;
	cnt /= 2;
	if (ans != w*h-cnt) yes = 0;
	if (yes) {
		std::cout << "Y\n";
	} else {
		std::cout << "N\n";
	}
}