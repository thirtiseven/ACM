#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61() {
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA; SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}

void gen() {
	unsigned int ans = 0;
	std::stack<int> a;
	std::priority_queue<int> maxx;
	std::cin >> n >> p >> q >> m >> SA >> SB >> SC;
	for (int i = 1; i <= n; i++) {
		if (rng61() % (p+q) < p) {
			unsigned int x = rng61() % m + 1;
			a.push(x);
			if (x > maxx.top()) {
				maxx.push(x);
			}
		} else {
			int y = a.top();
			POP();	
			if (y == maxx.top()) {
				maxx.pop();
			}
		}
		ans ^= (i * maxx.pop());
	}
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		ans = 0;
		gen();
	}
}