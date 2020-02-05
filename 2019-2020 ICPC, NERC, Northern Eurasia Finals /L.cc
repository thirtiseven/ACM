#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 1002;

int n, l, k;
std::string s[maxn], in;

int main(int argc, char *argv[]) {  
	std::cin >> n >> l >> k;
	std::cin >> in;
	std::sort(in.begin(), in.end());
	int sure = 0, pos = 0;
	while (sure < k-1) {
		for (int i = sure; i < k; i++) {
			s[i] += in[pos];
			if (pos > 0 && in[pos] != in[pos-1]) {
				sure = i;
			}
			pos++;
		}
		if (s[k-1].length() == l) {
			break;
		}
	}
	while (s[k-1].length() < l) {
		s[k-1] += in[pos];
		pos++;
	}
	for (int i = 0; i < n; i++) {
		while (s[i].length() < l) {
			s[i] += in[pos];
			pos++;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << s[i] << '\n';
	}
}