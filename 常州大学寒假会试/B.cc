#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, m;
	std::cin >> n >> m;
	long long cnt = 0, tot = 0;
	long long ans = 0;
	while (n%2==1) {
		cnt++;
		n/=2;
	}
	while (m%2==1) {
		tot++;
		m/=2;
	}
	long long f = 1;
	for (int i = 0; i < std::min(tot, cnt); i++) {
		ans += f;
		f *= 4;
	}
	std::cout << ans;
}