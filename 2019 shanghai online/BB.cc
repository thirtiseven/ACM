#include <iostream>
#include <algorithm>

const int maxn = 2004;

int modify[maxn];

template <class T>
inline bool Read(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-') ?-1:1 ;
	ret=(c=='-') ?0:(c -'0');
	while(c=getchar(),c>='0'&&c<='9')
		ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

int main(int argc, char *argv[]) {  
	int T;
	Read(T);
	for (int CAS = 1; CAS <= T; CAS++) {
		int n, m, l, r;
		n = read(), m = read();
		for (int i = 0; i < m; i++) {
			l = read(), r = read();
			modify[i] = l;
			modify[m+i] = r+1;
		}
		std::sort(modify, modify+2*m);
		int ans = 0;
		int cur = modify[0];
		int now = 1;
		for (int i = 1; i < 2*m; i++) {
			if (now) {
				ans += modify[i]-cur;
			}
			cur = modify[i];
			now = 1-now;
		}
		std::cout << "Case #" << CAS << ": " <<  ans << '\n';
	}

}