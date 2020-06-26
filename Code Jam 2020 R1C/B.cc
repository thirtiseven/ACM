#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using ll = long long;

ll u, q;
std::string r;
std::map<char, ll> num;
std::vector<std::pair<ll, char>> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T; std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		num.clear();
		ans.clear();
		std::cin >> u;
		for (int i = 0; i < 10000; i++) {
			std::cin >> q >> r;
			num[r[0]]+=10;
			for (int j = 0; j < r.length(); j++) {
				num[r[j]]++;
			}
		}
		for (auto it: num) {
			ans.push_back(std::make_pair(it.second, it.first));
		}
		std::sort(ans.begin(), ans.end());
		std::cout << "Case #" << _ << ": ";
		std::cout << ans[0].second;
		for (int i = ans.size()-1; i > 0; i--) {
			std::cout << ans[i].second;
		}
		std::cout << '\n';
//		std::cout << ans[0].first;
//		for (int i = ans.size()-1; i > 0; i--) {
//			std::cout << ' ' << ans[i].first;
//		}
//		std::cout << '\n';
	}
}