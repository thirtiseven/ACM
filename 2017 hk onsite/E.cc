#include <iostream>
#include <algorithm>
int p[100009];
int l, s;

bool check(int a) {
	int now = p[0];
	int ans = 1;
	for (int i = 0; i < l;) {
		do {
			i++;
			if(i >= l) {
				goto next;
			}
		} while(p[i]<now+a);
		now = p[i];
		ans++;
//		std::cout << now << " " << ans << '\n';
	}
	next:
	if (ans >= s) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {  
	while (std::cin >> l >> s) {
		if (l == 0 && s == 0) break;
		for (int i = 0; i < l; i++) {
			std::cin >> p[i];
		}
		std::sort(p, p+l);
		int left = 1, right = p[l-1]-p[0], middle;
		while (left <= right) {
			middle = (left + right)/2;
			if (check(middle)) {
				left = middle+1;
			} else {
				right = middle-1;
			}
//			std::cout << left << " " << middle << " " << right << '\n';
//			std::cout << check(left) << " " << check(middle) << " " << check(right) << '\n';
		}
		std::cout << right << '\n';
	}
	return 0;
}