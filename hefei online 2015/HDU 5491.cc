#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long

bool quick_in(ll &x) { 
	char c;
	while((c = getchar()) != EOF && !isdigit(c)); 
	if(c == EOF) {
		return false;
	}
	x = 0;
	do {
		x *= 10;
		x += c - '0'; 
	} while((c = getchar()) != EOF && isdigit(c)); 
	return true;
}

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		ll d, s1, s2;
		std::string bin;
		//std::cin >> d >> s1 >> s2;
		quick_in(d);
		quick_in(s1);
		quick_in(s2);
		label:
		int sum = 0;
		d++;
		for(int a = d; a; a /= 2) {   
			sum += (a % 2 ? 1 : 0);
		}  
		if(sum > s2) {
			goto label;
		}
		for(int a = d; a; a /= 2) {  
			bin += (a % 2 ? '1' : '0');  
		}  
		std::reverse(bin.begin(), bin.end());
		if(sum < s1) {
			for(int i = bin.length() - 1; i >= 0; i--) {  
				if(bin[i] == '0') {
					bin[i] = '1';
					sum++;
					if(sum >= s1) {
						break;
					}
				}
			} 
			//std::cout << bin << std::endl; 
		}
		ll dec = 0, w = 1;
		int n = bin.length();
		while(n--)
		{
			dec += (bin[n] - '0') * w;
			w *= 2;
		}
		std::cout << "Case #" << cas << ": " << dec << std::endl;
	}
	return 0;
}