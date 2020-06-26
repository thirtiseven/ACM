#include <iostream>
#include <string>

using ll = unsigned long long;
int T;
std::string s;

bool vowel(char c) {
	if (c == 'a') {
		return 1;
	}
	if (c == 'e') {
		return 1;
	}
	if (c == 'i') {
		return 1;
	}
	if (c == 'o') {
		return 1;
	}
	if (c == 'u') {
		return 1;
	}
	if (c == 'y') {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	int cas = 0;
	while (T--) {
		std::cin >> s;
		cas++;
		std::cout << "String #" << cas << ": ";
		bool yes = 1;
		int first = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '?' && first == -1) {
				first = int((i%2==0)^vowel(s[i]));
			}
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '?' && int((i%2==0)^vowel(s[i])) != first) {
				yes = 0;
			}
		}
		if (yes == 0) {
			std::cout << "0\n\n";
			continue;
		}
		ll ans = 1ll;
		if (first == -1) {
			ll ans2 = 1ll;
			for (int i = 0; i < s.length(); i++) {
				if (i%2ll) {
					ans *= 20ll;
					ans2 *= 6ll;
				} else {
					ans *= 6ll;
					ans2 *= 20ll;
				}
			}
			std::cout << ans + ans2 << "\n\n";
			continue;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '?') {
				if (i%2ll == 0) {
					ans *= (first?20ll:6ll);
				} else {
					ans *= (first?6ll:20ll);
				}
			}
		}
		std::cout << ans << "\n\n";
	}
}