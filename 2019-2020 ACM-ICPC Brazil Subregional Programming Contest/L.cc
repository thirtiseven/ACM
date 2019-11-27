#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	std::cout << (1ll << __builtin_popcountll(n)) << '\n';
}