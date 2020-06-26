#include <iostream>
#include <vector>

const int maxn = 103;

int n, T;
int a[maxn][maxn];
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> a[i][j];
			}
		}
		ans.push_back(0);
		for (int i=1; i<n; i++)
			insert(res, i);
	}
}