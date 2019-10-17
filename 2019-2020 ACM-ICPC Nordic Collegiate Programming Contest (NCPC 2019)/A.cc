#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 1e5+7;

std::string s;
int n;
std::string pool[maxn];

int cnt[28];

int main(int argc, char *argv[]) {  
	std::fill(cnt, cnt+28, 0);
	std::cin >> s >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> pool[i];
		cnt[int(pool[i][0]-'a')]++;
	}
	std::string ans1 = "", ans2 = "";
	char x = s[s.length()-1];
	for (int i = 0; i < n; i++) {
		int xx = pool[i][0] == pool[i][pool[i].length()-1]?1:0;
		if (pool[i][0] == x && cnt[int(pool[i][pool[i].length()-1]-'a')] == xx && ans2 == "") {
			ans2 = pool[i];
		}
		if (pool[i][0] == x && cnt[int(pool[i][pool[i].length()-1]-'a')] > 0 && ans1 == "") {
			ans1 = pool[i];
		}
	}
	if (ans1 == "" && ans2 == "") {
		std::cout << "?\n";
	} else if (ans2 != "") {
		std::cout << ans2 << "!\n";
	} else {
		std::cout << ans1 << '\n';
	}
}