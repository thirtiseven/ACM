#include <iostream>
#include <algorithm>
#include <string>
#define maxn 55

int arr[maxn], n;

template<class Cmp>  
int LIS (Cmp cmp) {  
	static int m, end[maxn];  
	m = 0;  
	for (int i=0; i<n; i++) {  
		int pos = lower_bound(end, end+m, arr[i], cmp)-end;  
		end[pos] = arr[i], m += pos==m;  
	}  
	return m;  
} 

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++) {
		arr[i] = (int)(s[i] - 'a');
	}
	std::cout << 26 - LIS(std::less<int>()) << std::endl;
	return 0;
}