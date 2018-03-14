#include <iostream>
#include <cstring>
#include <set>

int main(int argc, char *argv[]) {  
	int a[2009][1009], ans[1009][1009], n;
	memset(a, 0, sizeof(a));
	memset(ans, 0, sizeof(ans));
	std::set<int> p;
	std::cin >> n;
	bool vis[1009], yes;
	int cnt = 1;
	for (int i = 1; i <= 2*n; i++) {
		yes = 1;
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
			if (vis[a[i][j]]) {
				yes = 0;
			}
		}
		if (yes == 1) {
			p.insert(a[i][1]);
			for (int j = 1; j <= n; j++) {
				ans[cnt][j] = a[i][j];
				vis[a[i][j]] = 1;
			}
			cnt++;
		}
	}
	int ap = -3;
	for (int i = 1; i <= 2*n; i++) {
		bool doit = 1;
		for (int j = 1; j <= n; j++) {
			if (p.count(a[i][j]) == 0) {
				doit = 0;
				break;
			}
		}
		if (doit) {
			ap = i;
			break;
		}
	}
	
//	
//	std::cout << '\n';
//	std::cout << ap << std::endl;
//	std::cout << '\n';
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			std::cout << ans[i][j] << " ";
//		}
//		std::cout << '\n';
//	}
//	std::cout << '\n';
//	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[j][1] == a[ap][i]) {
				for (int h = 1; h <= n; h++) {
					if (!(h==1&&i==1)) std::cout << " ";
					std::cout << ans[j][h];
				}
				break;
			}
		}
	}
}