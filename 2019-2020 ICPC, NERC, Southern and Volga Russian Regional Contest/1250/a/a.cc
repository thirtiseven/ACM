#include <iostream>

const int maxn = 1e5+7;
const int maxm = 4e5+7;

int n, m;
int a[maxm];
int h[maxn], l[maxn], c[maxn], now[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		h[i] = l[i] = c[i] = now[i] = i;
	}
	int ppos, pcnt;
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
		if (c[a[i]] > 1) {
			ppos = c[a[i]];
			pcnt = now[ppos-1];
			std::swap(now[ppos], now[ppos-1]);
			std::swap(c[a[i]], c[pcnt]);
			h[a[i]] = std::min(h[a[i]], c[a[i]]);
			l[a[i]] = std::max(l[a[i]], c[a[i]]);
			h[pcnt] = std::min(h[pcnt], c[pcnt]);
			l[pcnt] = std::max(l[pcnt], c[pcnt]);
		} 
//		for (int i = 1; i <= n; i++) {
//			std::cout << now[i] << ' ';
//		}
//		std::cout << '\n';
//		for (int i = 1; i <= n; i++) {
//			std::cout << c[i] << ' ';
//		}
//		std::cout << '\n';
//		std::cout << "-----------------\n";
	}
	for (int i = 1; i <= n; i++) {
		std::cout << h[i] << ' ' << l[i] << '\n';
	}
}