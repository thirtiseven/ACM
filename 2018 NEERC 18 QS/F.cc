#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

int dig[30], pre[1007];

int init() {
	memset(dig, 0, sizeof(dig));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				dig[i+j+k]++;
				pre[i*100+j*10+k] = i+j+k;
			}
		}
	}
	for (int i = 1; i < 28; i++) {
		pre[i] = pre[i] + pre[i-1];
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	int n, a, b, luc, ans;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		a = std::stoi(s.substr(0, 3));
		b = std::stoi(s.substr(3, 3));
		luc = std::abs(a/100+a/10+a%10-(b/100+b/10+b%10));
		ans = 0;
		for (int i = 0; i < a; i++) {
			ans += dig[std::min(pre[i]+luc-1, 27)];
			ans -= dig[std::max(pre[i]-luc+1, 0)];0
			
		}
		std::cout << ans << '\n';
	}
}