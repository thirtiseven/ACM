#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string rhyme;
int n;
std::string children[123];
std::vector<std::string> team1, team2;
int vis[123];

int main(int argc, char *argv[]) { 
	std::fill(vis, vis+123, 0);
	getline(std::cin, rhyme);
	int cycle = 1;
	for (auto it: rhyme) {
		if (it == ' ') {
			cycle++;
		}
	}
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> children[i];
	}
	int cur = 0, now = 0, rnd = 0;
	while (rnd < n) {
//		std::cout << cur << ' ' << now << ' ' << rnd << '\n';
		if (!vis[cur]) {
			if (now == cycle-1) {
				vis[cur] = 1;
				if (rnd % 2 == 0) {
					team1.push_back(children[cur]);
//					std::cout << "team1 " << children[cur] << '\n';
				} else {
					team2.push_back(children[cur]);
//					std::cout << "team2 " << children[cur] << '\n';
				}
				rnd++;
			}
			cur ++;
			cur %= n;
			now ++;
			now %= cycle;
		} else {
			cur ++;
			cur %= n;
		}
	}
	std::cout << team1.size() << '\n';
	for (auto it: team1) {
		std::cout << it << '\n';
	}
	std::cout << team2.size() << '\n';
	for (auto it: team2) {
		std::cout << it << '\n';
	}
}