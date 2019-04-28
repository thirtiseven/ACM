#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cctype>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int T, n, m, ans, num;
int a[maxn];
int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') l = -1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * 1;
}
int main()
{
	T = read();
	while (T--) {
		int kill = 0, flag = 0;
		ans = 0;
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		if (n < 3) {
			printf("0\n");
			continue;
		}
		for (int i = 2; i < n; i++)
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
				ans++;
		for (int i = 3; i < n - 1; i++) {
			if (a[i - 2] < a[i - 1] && a[i - 1] > a[i] && a[i] < a[i + 1] && a[i + 1] > a[i + 2] && a[i - 1] == a[i + 1]) {
				flag = 1;
				printf("%d\n", ans - 2);
				break;
			}
		}
		if (flag) continue;
		if (a[1] < a[2] && a[2] > a[3]) kill = 1;
		if (a[n] < a[n - 1] && a[n - 1] >a[n - 2]) kill = 1;
		if (kill == 1) { printf("%d\n", ans - 1); continue; }
		for (int i = 2; i < n; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				if (a[i - 1] > a[i + 1]) {
					if (i == 2 || a[i - 1] <= a[i - 2]) {
						printf("%d\n", ans - 1);
						flag = 1;
						break;
					}
				}
				if (a[i - 1] < a[i + 1]) {
					if (i == n - 1 || a[i + 1] <= a[i + 2]) {
						printf("%d\n", ans - 1);
						flag = 1;
						break;
					}
				}
				if (a[i - 1] == a[i + 1]) {
					printf("%d\n", ans - 1);
					flag = 1;
					break;
				}
			}
			if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
				if (a[i - 1] == a[i + 1]) {
					if ((i > 2 && a[i - 1] > a[i - 2]) || (i<n - 1 && a[n + 1] > a[n + 2])) {
						printf("%d\n", ans - 1);
						flag = 1;
						break;
					}
				}
				else {
					if (a[i - 1] < a[i + 1]) {
						if (i > 2 && a[i - 2] < a[i - 1]) {
							printf("%d\n", ans - 1);
							flag = 1;
							break;
						}
					}
					if (a[i - 1] > a[i + 1]) {
						if (i < n - 1 && a[i + 2] < a[i + 1]) {
							printf("%d\n", ans - 1);
							flag = 1;
							break;
						}
					}
				}
			}
		}
		if (flag) continue;
		printf("%d\n", ans);
	}
	return 0;
}