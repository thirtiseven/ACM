#include <iostream>

const int maxn = 1e5+7;

int pos[maxn], a[maxn], op[maxn];

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]] = i+1;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> op[i];
	}
	for (int i = m-1; i >= 0; i--) {
		if (pos[op[i]]) {
			std::cout << op[i] << ' ';
			pos[op[i]] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (pos[a[i]]) {
			std::cout << a[i] << ' ';
		}
	}
}