#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 123;
using ll = long long;

ll l, m;

std::string raw_input, s;
ll p, c, t, r;

std::vector<std::pair<std::string, ll>> ans;

int main(int argc, char *argv[]) {  
	std::cin >> l >> m;
	getchar();
	ll minn = 10000000;
	for (ll i = 0; i < m; i++) {
		getline(std::cin, raw_input);
		std::vector<int> split;
		for (ll i = 0; i < raw_input.length(); i++) {
			if (raw_input[i] == ',') {
				split.push_back(i);
			}
		}
		split.push_back(raw_input.length());
		s = raw_input.substr(0, split[0]);
		p = stoll(raw_input.substr(split[0]+1, split[1]-split[0]-1));
		c = stoll(raw_input.substr(split[1]+1, split[2]-split[1]-1));
		t = stoll(raw_input.substr(split[2]+1, split[3]-split[2]-1));
		r = stoll(raw_input.substr(split[3]+1, split[4]-split[3]-1));
		if (10080*c*t >= l*(t+r)) {
//			std::cout << s << '\n';
			ans.push_back(std::make_pair(s, p));
			minn = std::min(minn, p);
		}
	}
	if (ans.size() == 0) {
		std::cout << "no such mower\n";
		exit(0);
	}
//	std::cout << minn << '\n';
	for (auto it: ans) {
		if (it.second == minn) {
			std::cout << it.first << '\n';
		}
	}
}