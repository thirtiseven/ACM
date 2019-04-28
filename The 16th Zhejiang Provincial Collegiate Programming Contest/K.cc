#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 2e6+7;
using ll = long long;

bool quick_in(char *p) { 
	char c;
	while((c = getchar()) != EOF && (c == ' ' || c == '\n')); 
	if(c == EOF) {
		return false; 
	}
	do {
		*p++ = c; 
	} while((c=getchar()) != EOF && c != ' ' && c != '\n'); 
	*p = 0;
	return true;
}

char s[maxn], t[maxn];
int T;
int ch[maxn][26],fail[maxn],len1[maxn],cnt=1,lst1,lst2,dep[maxn];
int Q[maxn<<1],l,r,n;ll ans;
void push_back(int i) {
	int p=lst1,x=Q[i]-'a';
	for(;Q[i]!=Q[i-len1[p]-1];p=fail[p]);
	if(!ch[p][x]) {
		int np=++cnt,q=fail[p];
		for(;Q[i]!=Q[i-len1[q]-1];q=fail[q]);
		len1[np]=len1[p]+2,fail[np]=ch[q][x],dep[np]=dep[fail[np]]+1;
		ch[p][x]=np;
	}
	lst1=ch[p][x];
	ans+=dep[lst1];
	if(len1[lst1]==r-l+1) lst2=lst1;
}


int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		int begin = -1, end = -1;
		quick_in(s+1);
		quick_in(t+1);
		int len = strlen(s+1);
		for (int i = 1; i <= len; i++) {
			if (s[i] != t[i]) {
				begin = i;
				break;
			}
		}
		for (int i = len; i > 0; i--) {
			if (s[i] != t[i]) {
				end = i;
				break;
			}
		}
		int xxx = 0;
		if (begin == -1 && end == -1) {
			ans = 0;
			fail[0]=fail[1]=1; len1[1]=-1;
			l=maxn,r=maxn-1;
			for(int i=1;i<=len;i++) Q[++r]=s[i],push_back(r);
			xxx = ans;
		} else {
			bool yes = 1;
			for (int i = 0; i < end-begin+1; i++) {
				if (s[begin+i] != t[end-i]) {
					yes = 0;
				}
			}
			if (!yes) {
				xxx = 0;
			} else {
				xxx = 1;
				begin--, end++;
				while (begin > 0 && end <= len && s[begin] == s[end]) {
					begin--, end++;
					xxx++;
				}
			}
		}
		std::cout << xxx << '\n';
	}
}