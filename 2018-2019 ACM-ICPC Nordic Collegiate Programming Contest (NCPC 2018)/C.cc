#include <iostream>

const int maxn = 370;

int n, d[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> d[i];
	}
	d[n] = 0;
	int id = 0, ans = 0, cur = 0, sum = 0;
	for (int i = 1; i <= 365; i++) {
		if (i == d[id]) {
			cur++;
			id++;
		}
		sum += cur;
		if (sum >= 20) {
			ans++;
			sum = 0;
			cur = 0;
		}
	}
	if (sum > 0) {
		ans++;
	}
	std::cout << ans << '\n';
}