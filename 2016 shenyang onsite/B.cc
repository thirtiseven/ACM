#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int T;
	int ans;
	std::string s;
	std::cin >> T;
	while(T--) {
		std::cin >> s;
		ans = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == 'H') {
				ans += 1;
			} else if(s[i] == 'C') {
				ans += 12;
			} else if(s[i] == 'O') {
				ans += 16;
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}