#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1234;

int n, a[maxn];

int cnt[maxn], unicorn;

std::vector<int> ans;

int main(int argc, char *argv[]) { 
	std::fill(cnt, cnt+maxn, 0); 
	ans.clear();
	std::cin >> n;
	unicorn = 0;
	bool yes = 1;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			cnt[a[i]]++;
		} else if (a[i] == 0) {
			unicorn++;
		} else {
			if (cnt[-a[i]] == 0 && unicorn == 0) {
				yes = 0;
			}
			if (cnt[-a[i]] > 0) {
				cnt[-a[i]]--;
			} else if (unicorn > 0) {
				unicorn--;
				ans.push_back(-a[i]);
			} else {
				yes = 0;
				goto outt;
			}
		}
	}
	outt:;
	if (yes) {
		std::cout << "Yes\n";
		for (auto it: ans) {
			std::cout << it << ' ';
		}
		while (unicorn--) {
			std::cout << "1 ";
		}
	} else {
		std::cout << "No\n";
	}
}