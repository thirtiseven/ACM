#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100005;
struct node{
	int l, r;
	bool operator < (const node nod) const {
		return l < nod.l || (l == nod.l && r > nod.r);
	}
};
int T, n, a, b;
int main(int argc, char *argv[]) {  
	scanf("%d", &T);
	while(T--){
		node no[maxn];
		int ans = 0, a = 0, b = 0;
		scanf("%d", &n);
		for(int nm = 1; nm <= n; nm++) {
			char s[maxn];
			scanf("%s", s+1);
			int temp = 0;
			int cnt = 0, len = strlen(s+1);
			for(int i = 1; i <= len; i++) {
				if(s[i]==')') {
					if(temp > 0) {
						temp--;
						ans++;
					}
					else no[nm].l++;
				}
				else {
					temp++;
				}
			}
			no[nm].r = temp;
		}
		sort(no + 1, no + n + 1);
		int temp = no[1].r;
		for(int i=2;i<=n;i++){
			if(temp > no[i].l){
				temp -= no[i].l;
				ans += no[i].l;
			}
			else {
				ans += temp;
				temp = 0;
			}
			temp += no[i].r;
		}
		printf("%d\n", ans*2);
	}
}