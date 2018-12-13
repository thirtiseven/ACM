#include <iostream>
#include <string>
#include <vector>

const int maxn = 100*26+7;

int n, m;		
int g[maxn][maxn];	//0-labeled
int linker[maxn];
bool used[maxn];

bool dfs(int u) {
	int v;
	for(v = 0; v < m; v++) {
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

int k;
int inx(int x) {
	return x*k;
}

int main(int argc, char *argv[]) {  
	int nn;
	std::string a[103], b[103], c[103];
	std::cin >> nn;
	for (int i = 0; i < nn; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	std::cin >> k;
	for (int i = 0; i < nn; i++) {
		int tmp[26] = {0};
		for (int j = 0; j < a[i].length(); j++) tmp[a[i][j] - 'A']++;
		for (int j = 0; j < b[i].length(); j++) tmp[b[i][j] - 'A']++;
		for (int j = 0; j < c[i].length(); j++) tmp[c[i][j] - 'A']++;
		int ma = 0;
		std::vector<int> v;
		for (int j = 0; j < 26; j++) {
			if (ma < tmp[j]) ma = tmp[j];
		}
		for (int j = 0; j < 26; j++) {
			if (tmp[j] == ma) v.push_back(j);
		}
		for (int j = 0; j < k; j++) {
			for (auto it: v) {
				int xx = it*k;
				g[i][xx+j] = 1;
//				std::cout << i << " " << xx+j << "\n";
			}
		}
	}
	n = 100, m = 26*100;
	std::cout << hungary() << '\n';
}