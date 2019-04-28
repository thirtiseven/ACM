#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn=1e7+1;

bool vis[maxn];
int prim[maxn];
int mu[maxn];
int cnt;

void get_mu(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prim[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt && prim[j]*i<=n;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
			else mu[i*prim[j]]=-mu[i];
		}
	}
}

ll gao(ll a, ll b) {
	if (a > b) {
		std::swap(a, b);
	}
	ll res = 0;
	for (ll i = 1; i <= a; i++) {
		res += mu[i]*(a/i)*(b/i);
	}
	return res;
}

int main(int argc, char *argv[]) {  
	ll a, b, c, d;
	std::cin >> a >> b >> c >> d;
	get_mu(std::min(b, d));
	ll ans = gao(b, d) - gao(a-1, d) - gao(b, c-1) + gao(a-1, c-1);
	std::cout << ans << '\n';
}