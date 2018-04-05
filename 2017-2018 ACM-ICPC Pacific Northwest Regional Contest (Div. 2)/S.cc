#include <iostream>
#include <string>
#include <cstring>

const int maxn = 1e5+9;
int dp[maxn][2];

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	s = ' '+s;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			if(s[j] == 'B') {
				dp[j][0] = dp[j-1][0];
				dp[j][1] = dp[j-1][0]+1;
			} else {
				dp[j][0] = dp[j-1][0]+1;
				dp[j][1] = dp[j-1][0];
			}
		}
	}
}