#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int cc[30];
	memset(cc, 0, sizeof(cc));
	for(int i = 0; i < s.length(); i++) {
		cc[int(s[i]-'a')]++;
	}
	std::sort(cc, cc+29);
	int ans = 0;
	for(int i = 0; i < 27; i++) {
		ans += cc[i];
	}
	std::cout << ans;
	return 0;
}