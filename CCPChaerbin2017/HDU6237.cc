#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define maxn 100010
#define LL long long int

std::vector<LL> prr;

int main(int argc, char *argv[]) {  
	bool prime_or_not[maxn+200];
	for (int i = 2; i <= int(sqrt(maxn)); i++) {
		if (!prime_or_not[i]) {
	    	for (int j = i * i; j <= maxn; j = j+i) {
				prime_or_not[j] = 1;
			}
		}
	}
	for(int i = 2; i < 100000; i++) {
		if(!prime_or_not[i]) {
			prr.push_back(i);
		}
	}
	LL size = prr.size();
	LL T;
	std::cin >> T;
	while(T--) {
		std::vector<LL> left;
		LL n, a[maxn];
		std::cin >> n;
		LL sum = 0;
		for(int i =0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		LL ans = 50000000000, tot, sss;
		for(int i = 0; i < size; i++) {
			tot = 0;
			//std::cout << prr[i] << " ";
			if(sum%prr[i] == 0) {
				left.clear();
				for(int j = 0; j < n; j++) {
					LL temp = a[j]%prr[i];
					tot += temp;
					left.push_back(temp);
				}
				std::sort(left.begin(), left.end());
				sss = 0;
				for(int j = left.size()-1; j > 0; j--) {
					sss += (prr[i] - left[j]);
					tot -= prr[i];
					if(tot <= 0) break;
				}
				ans = std::min(ans, sss);
				//std::cout << ans << " " << prr[i] << " ";
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}