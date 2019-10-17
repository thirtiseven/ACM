#include <iostream>

bool check(int x) {
	int cnt[11];
	std::fill(cnt, cnt+11, 0);
	while (x) {
		cnt[x%10]++;
		x /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		if (cnt[i] > 1) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	int l, r;
	std::cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (check(i)) {
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}