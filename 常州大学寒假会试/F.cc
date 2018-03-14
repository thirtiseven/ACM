#include <iostream>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int a, b, c, x, y, z, xy;
		std::cin >> a >> b >> c;
		int l = 0, r = 1000000, mid;
		while (l+1<r) {
			mid = (l+r)/2;
			xy = mid/2;
			x = a-mid, y = b-mid, z = c;
			if (x >= 0 && y >= 0 && x+y+z >= mid && x+y>=xy && x+z >= xy && y+z >= xy) {
				l = mid;
			} else {
				r = mid;
			}
		}
		std::cout << l << '\n';
	}
}