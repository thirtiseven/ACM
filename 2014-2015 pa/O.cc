#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

const int maxn = 1234;

struct d {
	double w, c;
};
d arr[maxn];
int dp[maxn];
int n;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for(int i=0; i<n; i++) {
			std::cin >> arr[i].w >> arr[i].c;
			dp[i]=1;
		}
		int ans=1;
		for(int i=1; i<n; i++) {
			for(int j=0; j<i; j++) {
				if(arr[i].w > arr[j].w && arr[i].c < arr[j].c) {
					dp[i]=std::max(dp[i],dp[j]+1);
				}
			}
			ans=std::max(ans,dp[i]);
		}
		std::cout<<ans<<std::endl;
	}
	
}