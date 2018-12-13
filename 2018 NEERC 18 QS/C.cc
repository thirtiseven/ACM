#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using ll = unsigned long long;

std::priority_queue<ll, std::vector<ll>, std::greater<ll>> b;

int main(int argc, char *argv[]) {  
	ll n, a;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		b.push(a);
	}
	ll ans = 0;
	while (b.size() > 1) {
		ll now = b.top();
		b.pop();
		ll mer = b.top();
		if (now == mer) {
			b.pop();
			b.push(2ll*now);
		} else if (2ll*now > mer) {
			std::cout << "-1\n";
			exit(0);
		} else {
			ans++;
			b.push(2ll*now);
		}
	}
	std::cout << ans << '\n';
}