#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	std::stack<std::pair<int, int>> ans;
	for (int i = 0; i < s.length()-1; i++) {
		char p = s[i];
		int res = 0;
		for (int j = i+1; j < s.length(); j++) {
			if (p > s[j]) {
				p = s[j];
				res = j;
			}
		}
		if (res != 0) {
			std::swap(s[res], s[i]);
			ans.push(std::make_pair(res+1, i+1));
		}
	}
	while (!ans.empty()) {
		std::cout << ans.top().first << " " << ans.top().second << '\n';
		ans.pop();
	}
}