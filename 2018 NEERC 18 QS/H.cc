#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m, x1, y1, x2, y2;
	std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	int ans = 0;
	ans += (n-(x2-x1+1))*(m%2);
	ans += (x2-x1+1)*((y1-1)%2+(m-y2)%2);
	ans += (ans%2);
	ans /= 2;
	std::cout << ans << '\n';
}