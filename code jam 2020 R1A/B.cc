#include <iostream>

int T, n;

int cal(int a, int b) {
	if (b == 1) {
		return 1;
	}
	return a-1;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int _=1; _<=T;_++) {
		std::cin >> n;
		std::cout << "Case #" << _ << ":\n";	
		int x = 1, y = 1;	
		for (int i = 1; i <= 500; i++) {
			std::cout << x << ' ' << y << '\n';
			n -= cal(x, y);
			if (n == 0) {
				break;
			} else if (y == 2) {
				y--;
			} else if (n >= cal(x+1, y+1)) {
				x++;
				y++;
			} else {
				x++;
			}
		}
	}		
}