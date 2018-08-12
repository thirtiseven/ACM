#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {  
	int n, k;
	std::string s;
	std::cin >> n >> k;
	std::cin >> s;
	s = "0" + s + "0";
	if (s[1] == '1') {
		k++;
	}	
	if (s[n] == '1') {
		k++;
	}
	int aa = 0;
	std::vector<int> ans;
	for (int i = 0; i <= n+1; i++) {
		if (s[i] == '1') {
			aa++;
		} else {
			if (aa) {
				ans.push_back(aa);
				aa = 0;
			}
		}
	}
	int num = 0;
	std::sort(ans.begin(), ans.end());
	std::reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size() && i < k/2+1 ; i++) {
		num += ans[i];
	}
	std::cout << num << '\n';
}