#include <iostream>
#include <set>

int main(int argc, char *argv[]) {  
	int n;
	std::multiset<int> a;
	while (std::cin >> n) {
		if (n == -1) {
			break;
		} else {
			if (n == 0) {
				int ans = 0;
				for (auto s: a) {
					ans += a.count(s*2);
				}
				std::cout << ans << '\n';
				a.clear();
			} else {
				a.insert(n);
			}
		}
	}
}