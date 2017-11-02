#include <iostream>
#include <set>
#include <cmath>

#define inf 1e9
#define LL int
#define abcd 50

int main(int argc, char *argv[]) { 
	std::set<int> zz;
	LL temp; 
	for(LL a = 0; a < abcd; a++) {
		for(LL b = 0; b < abcd; b++) {
			for(LL c = 0; c < abcd; c++) {
				for(LL d = 0; d < abcd; d++) {
					temp = pow(2,a)*pow(3,b)*pow(5,c)*pow(7,d);
					if(temp < inf) {
						zz.insert(temp);
					}
				}
			}
		}
	}
	int cnt = 0;
	for(auto it: zz) {
		std::cout << it << ",";
		cnt++;
	}
	std::cout << cnt;
	
	return 0;
}