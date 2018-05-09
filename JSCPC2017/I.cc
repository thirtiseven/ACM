#include <iostream>
#include <algorithm>

using ll = long long;

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	ll n, m, a, b;
	while (std::cin >> n >> m) {
		a = gcd(n, m);
		b = 2*m*n;
		ll gg = gcd(a, b);
		std::cout << a/gg << '/' << b/gg << '\n';
	}
}