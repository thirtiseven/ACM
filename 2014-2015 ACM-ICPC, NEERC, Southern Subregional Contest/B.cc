#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> aa;

const int maxk = 1009;

int vis[maxk];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> k >> n;
	int num[maxk], blan[maxk];
	std::fill(num, num+maxk, 0);
	for (int i = 0; i < k; i++) {
		std::cin >> blan[i];
		if (num[blan[i]] != -1) num[blan[i]]++;
	}
	int minn = k/n, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i]%minn!=0) {
			num[i] = (num[i]/minn+1)*minn;
			sum += num[i];
		}
	}
	if (sum > 2*n) {
		std::cout << "No\n";
		exit(0);
	}
	int l = 1, r = n;
	for (int i = 1; i <= k; i++) {
		while (num[l] == 0) l++;
		while (num[r] == 0) r--;
		if (l > r) break;
		for (int j = 0; j < minn; j++) {
			aa.push_back(std::make_pair(l, r));
			num[l]--;
			num[r]--;
		}
	}
	std::fill(vis, vis+maxk, 0);
	for (int i = 0; i < k; i++) {
		if (blan[i] == -1) {
			std::cout << "1 1\n";
			continue;
		}
		for (int i = 0; i < aa.size(); i++) {
			if (!vis[i] && (blan[i] == aa[i].first || blan[i] == aa[i].second)) {
				std::cout << aa[i].first << " " << aa[i].second << '\n';
				vis[i] = 1;
				goto after_output;
			}
		}
		std::cout << blan[i] << " 1\n";
		after_output:;
	}
}