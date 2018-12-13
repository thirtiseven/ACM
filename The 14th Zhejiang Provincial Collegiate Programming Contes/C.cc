#include <iostream>
#include <set>
#include <string>

const int maxq = 23;
const int maxn = 102;
const int maxc = 202;

int aa[maxc];
std::string friends[maxc];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n, q, c, m;
		std::cin >> n >> q >> c;
		std::set<std::string> qq[q];
		for (int i = 0; i < c; i++) {
			std::cin >> friends[i];
		}
		std::string s;
		for (int i = 0; i < q; i++) {
			std::cin >> m;
			for (int j = 0; j < m; j++) {
				std::cin >> s;
				qq[i].insert(s);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < q; j++) {
				std::cin >> aa[j];
			}
			int flag = 1;
			int cnt  = 0;
			int ans;
			for (int i = 0; i < c; i++) {
				flag = 1;
				for (int j = 0; j < q; j++) {
					if (qq[j].count(friends[i]) != aa[j]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					ans = i;
					cnt++;
				}
			}
			if (cnt == 1) {
				std::cout << friends[ans] << '\n';
			} else {
				std::cout << "Let's go to the library!!\n";
			}
		}
	}
}