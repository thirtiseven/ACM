#include <iostream>
#include <string>
#include <map>

int T, n, f;
std::string s;
std::map<int, int> m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		m.clear();
		for (int i = 0; i < n; i++) {
			std::cin >> s >> f;
			m[f]++;
		}
		int ans = -1, maxx = 0;
		for (auto it: m) {
			if (it.second > maxx) {
				maxx = it.second;
				ans = it.first;
			}
		}
		std::cout << ans << '\n';
	}
}