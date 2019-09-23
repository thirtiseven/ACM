#include <iostream>
#include <string>

const int maxn = 2e5+7;

std::string s;
int r9[maxn], l102[maxn][3], s8[maxn];

int main(int argc, char *argv[]) {  
	int n, q;
	std::cin >> n >> q >> s;
	s8[0] = 0;
	for (int i = 1; i <= n; i++) {
		s8[i] = s8[i-1];
		if (s[i-1] == '8') {
			s8[i]++;
		}
	}
	r9[n+1] = maxn;
	for (int i = n; i > 0; i--) {
		if (s[i-1] == '9') {
			r9[i] = i;
		} else {
			r9[i] = r9[i+1];
		}
	}
	l102[0][0] = l102[0][1] = l102[0][2] = -1;
	for (int i = 1; i <= n; i++) {
		l102[i][0] = l102[i-1][0];
		l102[i][1] = l102[i-1][1];
		l102[i][2] = l102[i-1][2];
		if (s[i-1] == '1') {
			l102[i][0] = i;
		} else if (s[i-1] == '0') {
			l102[i][1] = l102[i][0];
		} else if (s[i-1] == '2') {
			l102[i][2] = l102[i][1];
		}
	}
	int l, r;
	while (q--) {
		std::cin >> l >> r;
		if (r9[l] < l102[r][2]) {
			std::cout << s8[l102[r][2]] - s8[l-1] << '\n';
		} else {
			std::cout << "-1\n";
		}
	}
}