#include <iostream>
#include <map>
#include <cstring>

const int maxm = 100000;
std::map<int, int> miao;
int coin[12];
int ans[12];

void FindMin(int money, int n) {
	int coinNum[maxm];
	int coinValue[maxm];
	coinNum[0]=0;
	for(int i=1;i<=money;i++) {
		int minNum=i;
		int usedMoney=0;
		for(int j=0;j<n;j++) {
			if(i>=coin[j]) {
				if(coinNum[i-coin[j]]+1<=minNum && (i==coin[j] || coinValue[i-coin[j]]!=0)) {
					minNum = coinNum[i-coin[j]]+1;
					usedMoney = coin[j];
				}
			}
		}
		coinNum[i] = minNum;
		coinValue[i] = usedMoney;
	}
	if(coinValue[money]==0) {
		std::cout<<"-1"<<std::endl;
	} else {
		while(money>0) {
			ans[miao[coinValue[money]]]++;
			money-=coinValue[money];
		}
		for (int i = 0; i < n; i++) {
			std::cout << ans[i] << (i!=n-1?" ":"\n");
		}
	}
}

int main(int argc, char *argv[]) {
	int u, n;	
	while(std::cin >> u >> n) {
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++) {
			std::cin >> coin[i];
			miao[coin[i]] = i;
		}
		FindMin(u, n);
	}
}