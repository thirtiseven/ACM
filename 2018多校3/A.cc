#include <iostream>

const int maxn = 1e7+9;
using ll = long long;

ll a[maxn], que[maxn];
ll n, m, k, p, q, r, MOD;
ll A, B;

void DPmax() {
	ll head = 1, tail = 0;
	A = 0, B = 0;
	for(int i = n; i > 0; i--) {
		while (i+m-1 <= n && que[head] >= i+m) {
			head ++;
		}
		while(a[i] >= a[que[tail]] && head <= tail) {
			tail --;
		}
		que[++tail]=i;
		if(i+m-1 <= n){
			A += i^a[que[head]];
			B += i^(tail - head + 1);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k >> p >> q >> r >> MOD;
		for(int i = 1; i <= k; i++) {
			std::cin >> a[i];
		}
		for(int i = k+1; i <= n; i++) {
			a[i] = (p * a[i-1] + q * i + r) % MOD;
		}
		DPmax();
		std::cout << A << " " << B << "\n";
	}
}
