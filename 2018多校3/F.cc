#include <iostream>

#include <cctype>
int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

int main(int argc, char *argv[]) {  
	int T;
	T = read();
	while (T--) {
		int n;
		n = read();
		int u, v, t, ans;
		std::cin >> ans;
		for (int i = 1; i < n; i++) {
			t = read();
			ans = ans^t;
		} 
		for (int i = 0; i < n-1; i++) {
			u = read(), v = read();
		}
		if (ans == 0) {
			std::cout << "D\n";
		} else {
			std::cout << "Q\n";
		}
	}
}