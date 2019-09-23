#include <iostream>

using ll = long long;

ll W;

int gao(ll x, ll y) {
	ll r = 0, t = W+1-y, a = W+1-x, res;
	if (a<=t && (a+t <= W+1)) {   
		r = a;
		res = 4*(r-1)*W - 4*(r-1)*(r-1) +1 + t-r;
	} else if (a<=t && (a+t >= W+1)) {   
		r = W - t + 1;
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + W-2*r + 1 + a - r;
	} else if (a>=t && (a+t >= W+1)) {   
		r = W - a +1;
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + 3*W-6*r + 3 - t + r;
	} else if (a >=t && (a+t <= W+1)) {   
		r = t;   
		res =  4*(r-1)*W - 4*(r-1)*(r-1) + 1 + 4*W-8*r + 4  - a + r;
	}
	ll ans = 0;
	while (res) {
		ans += res%10;
		res /= 10;
	}
	return ans;
}
 

int main(int argc, char *argv[]) {  
	ll x, y;
	std::cin >> W;
	for (int i = W; i >= 1; i--) {
		for (int j = 1; j <= W; j++) {
			std::cout << gao(i, j) << ' ';
		}
		std::cout << '\n';
	}
	while (std::cin >> x >> y) {
		std::cout << gao(x, y) << '\n';
	}
}