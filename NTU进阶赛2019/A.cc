#include <iostream>
#include <cstring>

const int maxn = 1000000 + 7;
const int maxm = 10000 + 7;

int n, m, a[maxn], b[maxm];
int Next[maxn];


/*
* Author: Simon * 复 杂 度: O(n) 
*/

void getNext(int m) {
	memset(Next, 0, sizeof(int)*(m+5)); 
	int k = -1, j = 0;
	Next[0] = -1;
	while (j < m) {
		if (k==-1 || b[k] ==b[j]) { 
			k++, j++;
			if (b[k] != b[j]) Next[j] = k;
			else Next[j] = Next[k]; 
		}
		else k = Next[k]; 
	}
}

int KMP(int n, int m){
	int i = 0, j = 0; 
	while (i < n){
		if (j==-1||a[i]==b[j]) i++,j++;
		else j=Next[j];
		if(j==m) return i-m+1;
	}
	return -1; 
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			std::cin >> b[i];
		}		
		getNext(m);
		std::cout << KMP(n, m) << '\n';
	}
}