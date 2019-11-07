#include <iostream>

int T;
int a, b, c;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c;
		int sum = a+b+c;
		int minn = sum/3+int(sum%3>0);
		int ans = std::min(std::max(c/2+c%2, a), std::max(a/2+a%2, c));
		ans = std::max(ans, minn);
		std::cout << ans << '\n';
	}
}