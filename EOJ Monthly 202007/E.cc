#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

std::vector<std::pair<ll, ll>> v;
int cur[16];
ll n, p, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> p >> k;
		v.push_back(std::make_pair(p, k));
	}
	std::fill(cur, cur+16, 0);
	int tot = 1;
	for (int i = 0; i < n; i++) {
		tot *= (v[i].second + 1);
	}
	int now = v[0].first;
	cur[0] = 1;
	for (int i = 0; i < tot; i++) {
		std::cout << now << '\n';
		
	}
}