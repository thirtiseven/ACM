#include <iostream>
#include <algorithm>

struct t{
	int h, m, s;
}a[5009];

bool cmp(t a, t b) {
	if(a.h == b.h && a.m == b.m) {
		return a.s < b.s;
	} else if (a.h == b.h) {
		return a.m < b.m;
	}
	return a.h < b.h;
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].h >> a[i].m >> a[i].s;
	}
	std::sort(a, a+n, cmp);
	for (int i = 0; i < n; i++) {
		std::cout << a[i].h << ' ' << a[i].m << ' ' << a[i].s << '\n';
	}
}