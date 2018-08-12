#include <iostream>
#include <deque>

const int maxn = 150000+3;

//std::deque<int> a[maxn];
int n, q;
int u, v, w, val, op;

void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int main(int argc, char *argv[]) {  
	while (std::cin >> n >> q) {
		std::deque<int> a[n+1];
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for (int i = 0; i < q; i++) {
			read(op);
			if (op == 1) {
				read(u);
				read(w);
				read(val);
				if (w) {
					a[u].push_back(val);
				} else {
					a[u].push_front(val);
				}
			} else if (op == 2) {
				read(u);
				read(w);
				if (a[u].empty()) {
					std::cout << "-1\n";
					continue;
				}
				if (w) {
					std::cout << a[u].back() << '\n';
					a[u].pop_back();
				} else {
					std::cout << a[u].front() << '\n';
					a[u].pop_front();
				}
			} else if (op == 3) {
				read(u);
				read(v);
				read(w);
				if (w) {
					while (!a[v].empty()) {
						a[u].push_back(a[v].back());
						a[v].pop_back();
					}
				} else {
					while (!a[v].empty()) {
						a[u].push_back(a[v].front());
						a[v].pop_front();
					}
				}
			}
		}
	}
}