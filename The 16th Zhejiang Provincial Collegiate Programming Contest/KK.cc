#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define maxn 400050
s
int ch[maxn][26],fail[maxn],len[maxn],cnt=1,lst1,lst2,dep[maxn];
int Q[maxn<<1],l,r,n;ll ans;char s[maxn];
void push_back(int i) {
	int p=lst1,x=Q[i]-'a';
	for(;Q[i]!=Q[i-len[p]-1];p=fail[p]);
	if(!ch[p][x]) {
		int np=++cnt,q=fail[p];
		for(;Q[i]!=Q[i-len[q]-1];q=fail[q]);
		len[np]=len[p]+2,fail[np]=ch[q][x],dep[np]=dep[fail[np]]+1;
		ch[p][x]=np;
	}
	lst1=ch[p][x];
	ans+=dep[lst1];
	if(len[lst1]==r-l+1) lst2=lst1;
}
int main() {
	fail[0]=fail[1]=1; len[1]=-1;
	scanf("%s",s+1);
	l=maxn,r=maxn-1;
	int i;
	n=strlen(s+1);
	for(i=1;i<=n;i++) Q[++r]=s[i],push_back(r);
	int m,o;
	scanf("%d",&m);
}