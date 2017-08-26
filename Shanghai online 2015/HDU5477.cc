#include <iostream>
#include <algorithm>
#include <cmath>
#define inf 0x7f7f7f7f

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, a, b, l;
		std::cin >> n >> a >> b >> l;
		int strength = 0, minn = inf;
		int r = 0;
		int templ, tempr;
		for(int j = 0; j < n; j++) {
			std::cin >> templ >> tempr;
			strength += (templ - r) * b;
			strength -= (tempr - templ) * a;
			minn = std::min(minn, strength);
			r = tempr;
		}
		if(minn > 0) {
			minn = 0;
		}
		std::cout << "Case #" << i << ": " << -minn << std::endl;
	}
	return 0;
}