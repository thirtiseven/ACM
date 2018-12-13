#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cctype>

int read() {
	int x = 0, l = 1; char ch = getchar();
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

const int maxn = 1e5+7;

int a[maxn];
int belong[maxn];
int size[maxn];

int main(int argc, char *argv[]) {  
	int T;
	T = read();
	while (T--) {
		std::set<std::pair<int, int>> t;
		t.insert(std::make_pair(0, 0));
		int n = read();
		for (int i = 0; i <= n; i++) {
			size[i] = 0;
		}
		std::vector<int> res[n];
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			std::pair<int, int> aa = std::make_pair(a[i], i);
			auto it = t.upper_bound(aa);
			it--;
			if (it->second == 0) {
				t.insert(aa);
				belong[i] = cnt;
				res[cnt].push_back(i);
				cnt++;
			} else {
				t.insert(aa);
				size[it->second]++;
				belong[i] = belong[it->second];
				res[belong[i]].push_back(i);
				if (size[it->second] >= 2) {
					t.erase(it);
				}
			}
		}
		std::cout << cnt << '\n';
		for (int i = 0; i < cnt; i++) {
			std::cout << res[i].size();
			for (auto it: res[i]) {
				std::cout << " " << it;
			}
			std::cout << '\n';
		}
	}
}