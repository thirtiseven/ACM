#include <iostream>
#include <algorithm>

const int maxn = 123;

int n, m, s, d, sum = 0;
std::pair<int, int> c[maxn];

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second < b.second;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> s >> d;
	for (int i = 0; i < s; i++) {
		std::cin >> c[i].first;
		sum += c[i].first;
		c[i].second = i;
	}
	std::sort(c, c+s);
	int cur = n;
	bool flag = 0;
	for (int i = 0; i < s; i++) {
		if (cur == 0) {
			flag = 1;
		}
		if (flag) {
			c[i].first = 0;
		} else {
			int ori = c[i].first;
			int add = std::min(cur, d-ori);
			sum -= ori;
			cur -= add;
			c[i].first = add;
		}
	}
	if (sum < m || cur > 0) {
		std::cout << "impossible\n";
		exit(0);
	}
	std::sort(c, c+s, cmp);
	for (int i = 0; i < s; i++) {
		std::cout << c[i].first << ' ';
	}
}