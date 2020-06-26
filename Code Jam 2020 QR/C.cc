#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 1234;

int t, n;

struct act{
	int s, e, id;
}a[maxn];

bool cmp(act a, act b) {
	if (a.s == b.s) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CAS = 1; CAS <= t; CAS++) {
		std::cin >> n;
		std::string ans = "";
		int c = 0, j = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i].s >> a[i].e;
			a[i].id = i;
			ans += "X";
		}
		std::sort(a, a+n, cmp);
		for (int i = 0; i < n; i++) {
			if (a[i].s >= c) {
				ans[a[i].id] = 'C';
				c = a[i].e;
			} else if (a[i].s >= j) {
				ans[a[i].id] = 'J';
				j = a[i].e;
			} else {
				ans = "IMPOSSIBLE";
				break;
			}
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}