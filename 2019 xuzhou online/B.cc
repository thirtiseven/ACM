#include <iostream>
#include <set>

int n, q, op, x;
std::set<std::pair<int, int>> s;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> q;
	s.insert(std::make_pair(1, n));
	s.insert(std::make_pair(n+1, 0));
	for (int i = 0; i < q; i++) {
		std::cin >> op >> x;
		if (op == 1) {
			auto it = s.lower_bound(std::make_pair(x, n+1));
			it--;
			std::pair<int, int> a = std::make_pair((*it).first, x-1);
			std::pair<int, int> b = std::make_pair(x+1, (*it).second);
			s.erase(it);
			if (a.first <= x-1) {
				s.insert(a);
			}
			if (x+1 <= b.second) {
				s.insert(b);
			}
		} else {
			auto it = s.lower_bound(std::make_pair(x, 0));
			int ans = (*it).first;
			it--;
			if ((*it).first <= x && (*it).second >= x) {
				std::cout << x << '\n';
			} else {
				std::cout << ans << '\n';
			}
		}
	}
}