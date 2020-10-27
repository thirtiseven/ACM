#include <iostream>
#include <algorithm>

using ll = long long;

ll T, n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--)  {
		std::cin >> n >> m;
		if (n*m%2==0) {
			std::cout << "no\n";
		} else {
			std::cout << "yes\n";
		}
	}
}