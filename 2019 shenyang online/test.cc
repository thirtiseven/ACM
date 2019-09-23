#include <iostream>
#include <algorithm>

using ll = long long;
const ll mod = 1025436931;

struct matrix {		//矩阵 
	ll m[2][2];
}ans;
 
matrix base = {1, 1, 1, 0}; 
 
matrix multi(matrix a, matrix b) {	//矩阵相乘，返回一个矩阵 
	matrix tmp;
	for(ll i = 0; i < 2; i++) {
		for(ll j = 0; j < 2; j++) {
			tmp.m[i][j] = 0;
			for(ll k = 0;  k < 2; k++)
				tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
		}
	}
	return tmp;
}
 
ll matrix_pow(matrix a, ll n) {	//矩阵快速幂，矩阵a的n次幂 
	ans.m[0][0] = ans.m[1][1] = 1;	//初始化为单位矩阵 
	ans.m[0][1] = ans.m[1][0] = 0;
	while(n) {
		if(n & 1) ans = multi(ans, a);
		a = multi(a, a);
		n >>= 1;
	}
	return ans.m[0][1];
}

ll dis(ll x1, ll y1, ll x2, ll y2) {
	return std::abs(x1-x2) + std::abs(y1-y2);
}

int main(int argc, char *argv[]) {  
	ll T;
	std::cin >> T;
	while (T--) {
		ll n, m, a, b, c, d;
		std::cin >> n >> m >> a >> b >> c >> d;
		ll coner = 0, res;
		if (a == c && b == d) {
			std::cout << "1\n";
			continue;
		}
		if (dis(a, b, c, d) % 2 == 1) {
			if (std::min(n, m) >= 2) {
				std::cout << "countless\n";
				continue;
			} else {
				if (dis(1, m, a, b) > dis(1, m, c, d)) {
					res = dis(1, m, a, b);	
					coner = std::max(coner, res);		
				} 
				if (dis(n, 1, a, b) > dis(n, 1, c, d)) {
					res = dis(n, 1, a, b);	
					coner = std::max(coner, res);
				} 
				if (dis(1, 1, a, b) > dis(1, 1, c, d)) {
					res = dis(1, 1, a, b);	
					coner = std::max(coner, res);
				} 
				if (dis(n, m, a, b) > dis(n, m, c, d)) {
					res = dis(n, m, a, b);	
					coner = std::max(coner, res);
				}
				std::cout << (matrix_pow(base, coner+2)+mod-1)%mod << '\n';
				continue;
			}
		}
		if (dis(1, m, a, b) > dis(1, m, c, d)) {
			res = dis(1, m, a, b);	
			coner = std::max(coner, res);		
		} 
		if (dis(n, 1, a, b) > dis(n, 1, c, d)) {
			res = dis(n, 1, a, b);	
			coner = std::max(coner, res);
		} 
		if (dis(1, 1, a, b) > dis(1, 1, c, d)) {
			res = dis(1, 1, a, b);	
			coner = std::max(coner, res);
		} 
		if (dis(n, m, a, b) > dis(n, m, c, d)) {
			res = dis(n, m, a, b);	
			coner = std::max(coner, res);
		}
		std::cout << (matrix_pow(base, coner+1)+mod-1)%mod << '\n';
	}
}