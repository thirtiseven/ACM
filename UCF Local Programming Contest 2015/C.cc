#include <iostream>

int T, n, s, b, a;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		std::cin >> s >> b >> n;
		std::cout << "Practice #" << cas << ": " << s << ' ' << b << '\n';
		for (int i = 0; i < n; i++) {
			std::cin >> a;
			while (b <= a) {
				b *= 2;
			}
			b -= a;
			std::cout << a << ' ' << b << '\n';
		}
		std::cout << '\n';
	}
}