#include <iostream>
#include <map>

const int maxn = 1002;

int n;
std::pair<int, int> p[maxn];
std::map<std::pair<int, int>, int> mp;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mp[std::make_pair(p[i].first+p[j].first, p[i].second+p[j].second)]++;
		}
	}
	int ans = 0;
	for (auto it: mp) {
		ans = std::max(it.second, ans);
	}
	std::cout << n-ans << '\n';
}