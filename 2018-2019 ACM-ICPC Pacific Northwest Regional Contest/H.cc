#include <iostream>
#include <cstring>

const int maxn = 1e6+7;
int flag[maxn], primes[maxn], totPrimes;

void euler_sieve(int n) {
	totPrimes = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			primes[totPrimes++] = i;
		}
		for (int j = 0; i * primes[j] <= n; j++) {
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
			break;
		}
	}
}

int gao(int n) {
	for (int i = 0; primes[i] < n/2+1; i++) {
		if (!flag[n-primes[i]]) {
			return n-2*primes[i];
		}
	}
	return -1;
} 

int main(int argc, char *argv[]) {  
	int n;
	int ans = 0;
	std::cin >> n;
	euler_sieve(n);
	while (n >= 4) {
		n = gao(n);
		ans++;
	}
	std::cout << ans;
}