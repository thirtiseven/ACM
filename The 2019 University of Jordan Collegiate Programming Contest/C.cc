#include <iostream>

int main(int argc, char *argv[]) {  
	int s, x;
	std::cin >> s >> x;
	int ans = 0;
	while (s) {
		s/=x;
		ans++;
	}
	std::cout << ans << '\n';
}