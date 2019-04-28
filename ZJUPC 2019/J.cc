#include <cstdio>
#include <iostream>

int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

int T, n;

int main() {
	T = read();
	while (T--) {
		n = read();
		if (n&1) {
			printf("9 %d\n", n+9);
		} else {
			printf("4 %d\n", n+4);
		}
	}
}