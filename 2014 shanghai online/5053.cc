#include <iostream>

using ll = long long;

ll cubesum(ll n) {
	return (n*(n+1)/2)*(n*(n+1)/2);
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CC = 1; CC <= T; CC++) {
		ll a, b;
		std::cin >> a >> b;
		std::cout << "Case #" << CC << ": " << (cubesum(b) - cubesum(a-1)) << '\n';
	}
}