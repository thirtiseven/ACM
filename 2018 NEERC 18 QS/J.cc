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
	ll x, y, a, b;
	std::cin >> x >> y >> a >> b;
	ll aa = gcd(a, b);
	a = a/aa;
	b = b/aa;
	std::cout << std::min(x/a, y/b) << '\n';
}