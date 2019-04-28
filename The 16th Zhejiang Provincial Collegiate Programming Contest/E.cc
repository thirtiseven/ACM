#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

#include <cctype>

int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

int main(int argc, char *argv[]) {  
	int T;
	int n;
	int a[maxn], b[maxn];
	T = read();
	while (T--) {
		int ans = 0;
		n = read();
		for (int i = 0; i < n; i++) {
			b[i] = a[i] = read();
		}
		std::sort(b, b+n);
		int cnt = n-1;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] != b[cnt]) {
				ans++;
			} else {
				cnt--;
			}
		}
		std::cout << ans << '\n';
	}
}