#include <iostream>
#include <set>

std::set<int> res;

int main(int argc, char *argv[]) {  
	int temp;
	for (int i = 0; i < 10; i++) {
		std::cin >> temp;
		res.insert(temp);
	}
	int n;
	std::cin >> n;
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < 6; j++) {
			std::cin >> temp;
			if (res.count(temp)) {
				cnt++;
			}
		}
		if (cnt >= 3) {
			std::cout << "Lucky\n";
		} else {
			std::cout << "Unlucky\n";
		}
	}
}