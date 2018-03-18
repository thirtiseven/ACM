#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	long long tot = n*(n-1)/2;
	long long m = std::max(n/4-3, 1LL-1LL);
	while(m*(m-1) <= tot) {
		m++;
	}
	std::cout << n+1-m;
}