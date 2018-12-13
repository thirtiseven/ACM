#include <iostream>
#include <vector>

const int maxn = 1e5+7;

int a[maxn], n, k;
std::vector<int> ans;
int sum = 0;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if (sum%k != 0) {
		std::cout << "No\n";
		exit(0);
	}
	sum = sum/k;
	int now = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		now += a[i];
		cnt++;
		if (now == sum) {
			ans.push_back(cnt);
			now = 0;
			cnt = 0;
		} else if (now > sum) {
			std::cout << "No\n";
			exit(0);
		}
	}
	std::cout << "Yes\n";
	for (auto it: ans) {
		std::cout << it << " ";
	}
}