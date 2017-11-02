#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define LL long long
#define maxn 310

int main(int argc, char *argv[]) {  
	int n, k, t[maxn];
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		std::cin >> t[i];
	}
	for(int i = 1; i <= k; i++) {
		pq.push(t[i]);
	}
	LL ans = 0, pre = 0, tol = 0;
	int id = k+1;
	while(!pq.empty()){
		ans = pre + pq.top(); 
		pq.pop();
		pre = ans;
		tol += ans;
		if(id <= n) { 
			pq.push(t[id]); 
			id++; 
		}
	}
	std::cout << tol << std::endl;
	return 0;
}