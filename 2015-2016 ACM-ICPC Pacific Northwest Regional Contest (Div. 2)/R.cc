#include <iostream>
#include <string>
#include <algorithm>

struct name {
	std::string first, last;
};

bool cmp(name a, name b) {
	if(a.last == b.last) {
		return a.first < b.first;
	}
	return a.last < b.last;
}

int main(int argc, char *argv[]) {  
	int n;
	name a[110];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].last;
	}
	std::sort(a, a+n, cmp);
	for(int i = 0; i < n; i++) {
		std::cout << a[i].first << " " << a[i].last << '\n';
	}
	return 0;
}