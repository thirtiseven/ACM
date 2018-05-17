#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 321;

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::string m[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (m[i][k] == '1' && m[k][j] == '1') {
					m[i][j] = '1';
				}	
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = a[i], k = i;
		for (int j = i+1; j < n; j++) {
			if (cnt > a[j] && m[i][j] == '1') {
				k = j;
				cnt = a[j];
			}
		}
		std::swap(a[i], a[k]);
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}