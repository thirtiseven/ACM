#include <iostream>

const int maxn = 1e5+7;

int n, a[maxn], b[maxn];
int root[maxn];

void dfs(int al, int ar, int bl, int br, int root) {
	int len = ar-al;
	for (int i = 0; i < len; i++) {
		if ()
	}
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
	}
	root[0] = 0;
	dfs(0, n, 0, n);
}