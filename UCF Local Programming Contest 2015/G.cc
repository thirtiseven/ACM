#include <iostream>

int T, n, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	int cas = 0;
	while (T--) {
		cas++;
		std::cin >> d >> n;
		std::string x = std::to_string(d*2*(n-1));
		std::cout << "Grid #" << cas << ": " << (d-1>(n-1)*(n-1)?"impossible":x) << '\n';
	}
}