#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

const int maxn = 123;

struct stu{
	std::string id;
	double tem;
	std::string date;
}a[maxn];

int n;

std::vector<stu> b;

bool cmp(stu x, stu y) {
	if (x.date == y.date) {
		if (x.tem == y.tem) {
			return x.id < y.id;
		}
		return x.tem > y.tem;
	}
	return x.date > y.date;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].date >> a[i].id >> a[i].tem;
		if (a[i].tem >= 38.0) {
			b.push_back(a[i]);
		}
	}
	std::sort(b.begin(), b.end(), cmp);
	std::cout << b.size() << '\n';
	for (auto it: b) {
		std::cout << it.date << ' ' << it.id << ' ' << std::fixed << std::setprecision(1) << it.tem << '\n';
	}
}