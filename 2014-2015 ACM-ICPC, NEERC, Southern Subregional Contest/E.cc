#include <iostream>
#include <vector>

const int maxn = 2e5+7;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n;
	int awin = 0, bwin = 0, tier = 0;
	std::pair<int, int> a[maxn];
	std::vector<std::pair<int, int>> ans;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second) {
			awin++;
		}
	}
	if (awin*2 > n) {
		std::cout << "0\n";
		exit(0);
	}
	int cc = n;
	for (int i = 0; i < cc-1;) {
		if (a[i].first > a[i].second) {
			if (a[i+1].first <= a[i+1].second) {
				if (a[i].first + a[i+1].first > a[i].second + a[i+1].second) {
					n--;
					ans.push_back(std::make_pair(i+1, i+2));
					if (awin*2 > n) {
						std::cout << ans.size() << '\n';
						for (auto it: ans) {
							std::cout << it.first << " " << it.second << '\n';
						}
						exit(0);
					}
					i+=2;
					continue;
				}
			}
		} else {
			if (a[i+1].first > a[i+1].second) {
				if (a[i].first + a[i+1].first > a[i].second + a[i+1].second) {
					n--;
					ans.push_back(std::make_pair(i+1, i+2));
					if (awin*2 > n) {
						std::cout << ans.size() << '\n';
						for (auto it: ans) {
							std::cout << it.first << " " << it.second << '\n';
						}
						exit(0);
					}
					i+=2;
					continue;
				}
			} else {
				n--;
				ans.push_back(std::make_pair(i+1, i+2));
				if (awin*2 > n) {
					std::cout << ans.size() << '\n';
					for (auto it: ans) {
						std::cout << it.first << " " << it.second << '\n';
					}
					exit(0);
				}
				i+=2;
				continue;
			}
		}
		i++;
	} 
	std::cout << "-1\n";
}