#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int cnt[28], num[maxn][28], s[maxn][28];
int sall[maxn][28];
inline int f(int x) { return x > 0 ? x : -x; }
int main()
{
	cnt[0] = 1; num[0][0] = 1;
	for (int i = 1; i < 1000; i++) {
		for (int j = 0; j <= 27; j++)
			num[i][j] = num[i - 1][j];
		int sum = 0;
		int ti = i;
		while (ti > 0) {
			sum += ti % 10;
			ti /= 10;
		}
		num[i][sum]++;
		cnt[sum]++;
	}
	for (int i = 0; i < 1000; i++) {
		int sum = 0;
		int ti = i;
		while (ti > 0) {
			sum += ti % 10;
			ti /= 10;
		}
		s[i][0] = cnt[sum];
		for (int j = 1; j < 28; j++) {
			int sa = 0, sb = 0;
			if (sum - j >= 0) sa = cnt[sum - j];
			if (sum + j <= 27) sb = cnt[sum + j];
			s[i][j] = sa + sb;
		}
	}
	for (int i = 0; i < 28; i++)
		sall[0][i] = s[0][i];
	for (int i = 1; i < 1000; i++)
		for (int j = 0; j < 28; j++)
			sall[i][j] = s[i][j] + sall[i - 1][j];
	int n; scanf("%d", &n);
	char t[10];
	while (n--) {
		scanf("%s", &t);
		int a = 0, b = 0, na = 0, nb = 0;
		for (int i = 0; i < 3; i++)
			a += t[i] - '0', na = na * 10 + t[i] - '0';
		for (int i = 3; i < 6; i++)
			b += t[i] - '0', nb = nb * 10 + t[i] - '0';
		int d = f(a - b) - 1;
		if (d == -1) { printf("0\n"); continue; }
		int ans = 0;
		for (int i = 0; i <= d; i++)
			ans += sall[na - 1][i];
		int mi = max(0, a - d), ma = min(27, a + d);
		if(nb) for (int i = mi; i <= ma; i++)
			ans += num[nb - 1][i];
		printf("%d\n", ans);
	}
	return 0;
}