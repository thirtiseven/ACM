#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int N = 3000 + 10;
const int M = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
const int oo = 1000000;
#define pb push_back
int n,x[N],y[N],l[N],r[N];
 
void get(int &n, int l, int r){
	scanf("%d",&n);
}

std::vector<int> g[N];
int du[N], xx[N];
bool flag = 1;

bool topsort() {
	std::fill(du, du+N, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			du[g[i][j]]++;
		}
	}
	int tot = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for(int i = 0; i < n; i++) {
		if(!du[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int x = q.top();
		q.pop();
		xx[tot++] = x;
		for(int j = 0; j < g[x].size(); j++) {
			int t = g[x][j];
			du[t]--;
			if(!du[t]) {
				q.push(t);
			}
		}
	}
	if(tot == n) {
		return 1;
	}
	return 0;
}


int main(){
	get(n,1,3000);
	for(int a,rn,i=0; i<n; ++i){
		get(x[i], -oo, oo);
		get(y[i], -oo, oo);
		get(a, 0, 359);
		get(rn, 0, 89);
		l[i]=(a-rn+360)%360;
		r[i]=(a+rn)%360;
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i==j)continue;
			int dx=x[j]-x[i], dy=y[j]-y[i];
			double ang=atan2(dy,dx);
			if(ang<0)
				ang+=2*PI;
			ang*=180/PI;
			if(l[i]>r[i]){
				if(ang+eps>=l[i] || ang-eps<=r[i])
					g[i].push_back(j);
			}else if(ang+eps>=l[i] && ang-eps<=r[i])
				g[i].push_back(j);
		}
	}
	if (topsort()) {
		for (int i = 0; i < n; i++) {
			std::cout << xx[i]+1 << " ";
		}
	} else {
		std::cout << "-1\n";
	}
}