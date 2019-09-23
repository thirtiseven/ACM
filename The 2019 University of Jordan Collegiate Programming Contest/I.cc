#include <iostream>
#include <stack>
#include <string>

const int maxn = 1e6;

int ans[maxn];
std::stack<int> stk;

int isnum(char c) {
	if (c >= '0' && c <= '9') {
		return int(c-'0');
	} else if (c == '(') {
		return -1;
	}
	return -2;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::string s;
	std::cin >> n >> s;
	int num = 0;
	for (int i = 0; i < s.length(); i++) {
		int cur = isnum(s[i]);
		if (cur == -1) {
			if (num != 0) {
				stk.push(num);
//				std::cerr << "push " << num << " into stack."<< '\n';
				num = 0;
			} else {
//				std::cerr << "did nothing.\n";
			}
		} else if (cur == -2) {
			if (num != 0) {
				ans[num] = stk.top();
//				std::cerr << num << "'s father is " << stk.top() << '\n';
				num = 0;
			} else if (s[i-1] == ')') {
				num = stk.top();
				stk.pop();
				ans[num] = stk.top();
//				std::cerr << "pop " << num << ". "<< num << "'s father is " << stk.top() << '\n';
				num = 0;
			}
		} else {
			num = num*10+cur;
//			std::cerr << "current num is " << num << '\n';
		}
	}
	for (int i = 1; i <= n; i++){
		std::cout << ans[i] << ' ';
	}
}