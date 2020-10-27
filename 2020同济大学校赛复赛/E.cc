#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

struct RMQ {
	std::vector<std::vector<int> > rmq;
	// vector<int> rmq[20]; or int[100002][20] if need speed
	//int kInf = numeric_limits<int>::max(); // if need return a value when the interval fake
	void init(const std::vector<int>& a) { // 0 base
		int n = (int)a.size(), base = 1, depth = 1;
		while (base < n)
			base <<= 1, ++depth;
		rmq.assign((unsigned)depth, a);
		for (int i = 0; i < depth - 1; ++i)
			for (int j = 0; j < n; ++j) {
				rmq[i + 1][j] = std::max(rmq[i][j], rmq[i][std::max(n - 1, j + (1 << i))]);
			}
	}
	int q(int l, int r) { // [l, r)
		if(l>r)return 0x3f3f3f3f;
		int dep = 31 - __builtin_clz(r - l); // log(b - a)
		return std::max(rmq[dep][l], rmq[dep][r - (1 << dep)]);
	}
};

RMQ pp;

const int maxn = 1e6+7;
char s[maxn], str[maxn << 1];
//int p[maxn << 1];
std::vector<int> p(maxn << 1);

void Manacher(char s[], int n) {
	str[0] = '$', str[1] = '#';
	for (int i = 0; i < n; i++) str[(i << 1) + 2] = s[i], str[(i << 1) + 3] = '#';
	n = 2 * n + 2;
	str[n] = 0;
	int mx = 0, id;
	for (int i = 1; i < n; i++) {
		p[i] = mx > i ? std::min(p[2 * id - i], mx - i) : 1;
		while (str[i - p[i]] == str[i + p[i]]) p[i]++;
		if (p[i] + i > mx) mx = p[i] + i, id = i;
	}
	for (int i = 1; i < n; i++) {
		p[i]--;
	}
	pp.init(p);
}

void solve(char s[]) {
	int n = strlen(s);
	Manacher(s, n);	
//	for (int i = 1; i < 2 * n + 2; i++) {
//		std::cout << p[i] << ' ';
//	}
//	std::cout << '\n';
}

int q, l, r;

bool check(int x) {
//	std::cout << l << ' ' << r << ' ' << x << ' ' <<  l*2+(x+1)/2 << ' ' << r*2-(x+1)/2+1 << ' ' << pp.q(l*2+(x+1)/2, r*2-(x+1)/2+1);
	if (pp.q(l*2+(x+1)/2, r*2-(x+1)/2+1) >= x) {
//		std::cout << ' ' << 1 << '\n';
		return 1;
	}
//	std::cout << ' ' << 0 << '\n';
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> s;
	solve(s);
	std::cin >> q;
	while (q--) {
		std::cin >> l >> r;
		int left = 1, right = (r-l+1), mid;
		while (left <= right) {
			mid = (left+right)/2;
			if (check(mid)) {
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		std::cout << left << '\n';
	}
}