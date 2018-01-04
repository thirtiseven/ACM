#include <iostream>

#define maxn 13

int main(int argc, char *argv[]) {  
	int n, h[maxn], t;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	std::cin >> t;
	int maxx = t+10;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(maxx > t%h[i]) {
			maxx = t%h[i];
			ans = h[i];
		}
	}
	std::cout << ans << std::endl;
	return 0;
}