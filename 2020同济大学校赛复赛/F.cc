#include <iostream>
#include <algorithm>
#include <set>

const int maxn = 1e6+7;
std::set<int> now;
int n, a[maxn], last = -1, ans = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == last) {
			ans++;
			now.clear();
		} else if (!now.count(a[i])) {
			now.insert(a[i]);
		} else {
			now.clear();
			ans += 2;
			last = a[i];
		}
	}
	std::cout << ans << '\n';
}