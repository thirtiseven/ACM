#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

struct point {
	int x, y, z;
	point(int a, int b, int c){
		x = a, y = b, z = c;
	}
};

std::vector<point> ans;
int vis[103][103][103];

int main(int argc, char *argv[]) {  
	int pp[5], a, b, c;
	ans.clear();
	memset(vis, 0, sizeof(vis));
	std::cin >> a >> b >> c;
	pp[0] = a, pp[1] = b, pp[2] = c;
	std::sort(pp, pp+3);
	if (pp[0]*pp[1] < pp[2]) {
		std::cout << "-1\n";
		exit(0);
	}
	if (a == pp[2]) {
		for (int i = 0; i < pp[0]; i++) {
			ans.push_back(point(i, i, 0));
			vis[i][i][0] = 1;
		}
		if (b == pp[1]) {
			for (int i = pp[0]; i < pp[1]; i++) {
				ans.push_back(point(i, pp[0]-1, 0));
				vis[pp[0]-1][i][0] = 1;
			}
			int now = pp[1];
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[i][j][0]) {
						ans.push_back(point(i, j, 0));
						vis[i][j][0] = 1;
						now++;
					}
				}
			}
		} else {
			for (int i = pp[0]; i < pp[i]; i++) {
				ans.push_back(point(pp[0]-1, i, 0));
				vis[pp[0]-1][i][0] = 1;
			}
			int now = pp[1]; 
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[j][i][0]) {
						ans.push_back(point(j, i, 0));
						vis[j][i][0] = 1;
						now++;
					}
				}
			}
		}
	} else if (b == pp[2]) {
		for (int i = 0; i < pp[0]; i++) {
			ans.push_back(point(i, 0, i));
			vis[i][0][i] = 1;
		}
		if (c == pp[1]) {
			for (int i = pp[0]; i < pp[1]; i++) {
				ans.push_back(point(i, 0, pp[0]-1));
				vis[i][0][pp[0]-1] = 1;
			}
			int now = pp[1];
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[i][0][j]) {
						ans.push_back(point(i, 0, j));
						vis[i][0][j] = 1;
						now++;
					}
				}
			}
		} else {
			for (int i = pp[0]; i < pp[1]; i++) {
				ans.push_back(point(pp[0]-1, 0, i));
				vis[pp[0]-1][0][i] = 1;
			}
			int now = pp[1];
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[j][0][i]) {
						ans.push_back(point(j, 0, i));
						vis[j][0][i] = 1;
						now++;
					}
				}
			}
		}
	} else {
		for (int i = 0; i < pp[0]; i++) {
			ans.push_back(point(0, i, i));
			vis[0][i][i] = 1;
		}
		if (a == pp[1]) {
			for (int i = pp[0]; i < pp[1]; i++) {
				ans.push_back(point(0, i, pp[0]-1));
				vis[0][i][pp[0]-1] = 1;
			}
			int now = pp[1];
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[0][j][i]) {
						ans.push_back(point(0, j, i));
						vis[0][j][i] = 1;
						now++;
					}
				}
			}
		} else {
			for (int i = pp[0]; i < pp[1]; i++) {
				ans.push_back(point(0, pp[0]-1, i));
				vis[0][pp[0]-1][i] = 1;
			}
			int now = pp[1];
			for (int i = 0; i < pp[1]; i++) {
				for (int j = 0; j < pp[0]; j++) {
					if (now >= pp[2]) break;
					if (!vis[0][i][j]) {
						ans.push_back(point(0, i, j));
						vis[0][i][j] = 1;
						now++;
					}
				}
			}
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it.x << " " << it.y << " " << it.z << '\n';
	}
}