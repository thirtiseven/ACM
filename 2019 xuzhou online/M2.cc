#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define maxn 1000005
using namespace std;
int n, m, tot[30];
string s, t;

int main() {  
	memset(tot, 0, sizeof(tot));
	cin >> n >> m >> s >> t;
	int res = -1;
	for (int i = 0, j = 0; i < n && j < m; i++) {
		for (int k = 0; k < 26; k++) {
			if (tot[k] && k < int(s[i]-'a')) {
				res = max(tot[k]+n-1-i, res);
			}
		}
		if (s[i] == t[j]) {
			j++;
			tot[int(s[i]-'a')] = j;
		}
		if (j >= m && i != n-1) {
			res = max(res, j+n-1-i);
		}
	}
	cout << res << endl;
}