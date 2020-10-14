#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 1e5+7;

int T, n, a[maxn], p;
std::map<int, int> pre;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> p;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int ans = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			cur += a[i];
			cur %= p;
			if (cur == 0 || pre[cur] != 0) {
				pre.clear();
				cur = 0;
				ans++;
			} else {
				pre[cur] = 1;
			}
		}
		std::cout << ans << '\n';
	}
}


// whaaaaaat happend?