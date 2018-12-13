#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int T, n; scanf("%d", &T);
	char s[1005];
	while (T--) {
		int num, mul, cntn, cntm, ans, loc, lc;
		num = mul = cntn = cntm = ans = 0;
		lc = -1;
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			s[i] == '*' ? cntm++, loc = i : cntn++;
			if (lc == -1 && s[i] == '*')lc = i;
		}
		if (cntm == 0) { puts("1"); continue; }
		if (s[n - 1] != '*')s[lc] = s[n-1], s[n - 1] = '*', ans++;
		if (cntn <= cntm) {
			ans += (cntm + 1 - cntn);
			num = ans;
		}
		for (int i = 0; i < n; i++) {
			s[i] == '*' ? mul++ : num++;
			if (mul == num) {
				mul--; num++;
				while (s[loc] == '*') loc--;
				s[loc] = '1';
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}