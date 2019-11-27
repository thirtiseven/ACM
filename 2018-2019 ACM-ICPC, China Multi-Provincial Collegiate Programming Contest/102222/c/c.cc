#include<bits/stdc++.h>
using namespace std;
char a[55], b[55], c[55];
char f(char c, int k, int d) {
	if (d) {
		char ret = c + k;
		if (ret > 'Z') return ret - 26;
		else return ret;
	} else {
		char ret = c - k;
		if (ret < 'A') return ret + 26;
		else return ret;
	}
}
int main()
{
	int T, n, m;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d%d", &n, &m);
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		scanf("%s", c + 1);
		int d, k;
		if (b[1] > a[1]) {
			d = 0;
			k = b[1] - a[1];
		} else {
			d = 1;
			k = a[1] - b[1];
		}
		printf("Case #%d: ", ca);
		for (int i = 1; i <= m; i++)
			printf("%c", f(c[i], k, d));
		printf("\n");
	}
	return 0;
}