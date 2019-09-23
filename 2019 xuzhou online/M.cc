#include <iostream>
#include <string>
#include <algorithm>

std::string s, t;
const int maxn = 1e6+7;

int vis[30], num[30];

int main(int argc, char *argv[]) {  
	for (int i = 0; i < 26; i++) {
		vis[i] = 0;
		num[i] = 0;
	}
	int n, m;
	std::cin >> n >> m;
	std::cin >> s >> t;
	n = s.length();
	m = t.length();
	int ans = 0;
	int pos = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (vis[j] && j < int(s[i]-'a')) {
				ans = std::max(num[j]+n-i, ans);
			}
		}
		if (s[i] == t[pos]) {
			num[int(s[i]-'a')] = cur;
			vis[int(s[i]-'a')] = 1;
			pos++;
			cur++;
		} else if (s[i] > t[pos]) {
			ans = std::max(cur+n-i, ans);
		}
		if (pos>=m) {
			if (i != n-1) {
				ans = std::max(cur+n-i-1, ans);
			}
			break;
		}
	}
	if (ans == 0) {
		ans = -1;
	}
	std::cout << ans << '\n';
}