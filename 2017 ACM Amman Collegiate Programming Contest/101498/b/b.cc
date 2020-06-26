#include <iostream>
#include <string>
#include <algorithm>

int T;
std::string a, b;
int num[30];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		std::fill(num, num+30, 0);
		for (auto it: b) {
			num[int(it-'a')]++;
		}
		int ans = 0;
		for (int i = 0; i < a.size(); i++) {
			if (num[int(a[i]-'a')] > 0) {
				num[int(a[i]-'a')]--;
				ans++;
			} else {
				break;
			}
		}
		std::cout << ans << '\n';
	}
}