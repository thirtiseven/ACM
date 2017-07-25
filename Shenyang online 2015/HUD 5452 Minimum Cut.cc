#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <cstring>
#define maxn 22000
  
int t[maxn];
int flag[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	int times = T;
	int n, m, u, v, ans;
	while(T--) {
		memset(t, 0, sizeof(t));
		memset(flag, 0, sizeof(flag));
		ans = maxn * 10 + 10;
		std::cin >> n >> m;
		for(int i = 0; i < n - 1; i++) {
			std::cin >> u >> v;
			t[u]++;
			t[v]++;
		}
		for(int i = 0; i < maxn; i++) {
			if(t[i] == 1) {  
				flag[i] = 1;
			}
		}
		for(int i = n; i <= m; i++) {
			std::cin >> u >> v;
			t[u]++;
			t[v]++;
		}
		for(int i = 1; i <= n; i++) { 
			if(flag[i]) {
				if(t[i] < ans) {
					ans = t[i];
				}
			}
		}
		std::cout << "Case #" << times  - T << ": " << ans << "\n";
	}
	return 0;
}	

	