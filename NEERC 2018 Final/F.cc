#include <iostream>

const int maxn = 1e5+7;

int cnt[maxn];//存储质因子是什么
int num[maxn];//该质因子的个数
int tot = 0;//质因子的数量
void factorization(int x) {
	for(int i=2;i*i<=x;i++) {
		if(x%i==0) {
			cnt[tot]=i;
			num[tot]=0;
			while(x%i==0) {
				x/=i;
				num[tot]++;
			}
			tot++;
		}
	}
	if(x!=1) {
		cnt[tot]=x;
		num[tot]=1;
		tot++;
	}
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	factorization(n);
}