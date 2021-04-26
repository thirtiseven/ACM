#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

int q, op, m;

struct cmp1{
	bool operator() (const std::pair<int, int> &a, const std::pair<int, int> &b) {
		return a.first < b.first; 
	}
};

struct cmp2{
	bool operator() (const std::pair<int, int> &a, const std::pair<int, int> &b) {
		if (a.second == b.second) {
			return a.first < b.first; 
		}
		return a.second > b.second;
	}
};

std::set<std::pair<int, int>, cmp1> a;
std::set<std::pair<int, int>, cmp2> b;
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> q;
	int cnt = 1;
	while (q--) {
		std::cin >> op;
		if (op == 1) {
			std::cin >> m;
			a.insert(std::make_pair(cnt, m));
			b.insert(std::make_pair(cnt, m));
			cnt++;
		} else if (op == 2) {
			std::pair<int, int> it = *a.begin();
			ans.push_back(it.first);
			a.erase(it);
			b.erase(it);
		} else {
			std::pair<int, int> it = *b.begin();
			ans.push_back(it.first);
			a.erase(it);
			b.erase(it);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << '\n';
}