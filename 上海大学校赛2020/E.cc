#include <iostream>

using ll = long long;

const int maxn = 1e5+7;

ll n, a[maxn], sum = 0;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		sum -= cnt;
		cnt++;
	}
	std::cout << sum << '\n';
}