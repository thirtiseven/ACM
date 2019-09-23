#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

const int maxn = 3010;
using ld = double;
const ld PI = acos(-1.0);
const ld eps = 1e-9;

int x[maxn], y[maxn], a[maxn], r[maxn];
std::vector<int> g[maxn];
int du[maxn], n, l[maxn];
bool flag = 1;

bool topsort() {
	std::fill(du, du+maxn, 0);
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
		l[tot++] = x;
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

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i] >> a[i] >> r[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				ld ang = atan2(y[j]-y[i], x[j]-x[i]);
				if (ang < 0) {
					ang += 2*PI;
				}
				ang *= 180/PI;
				int lower = (a[i]-r[i]+360)%360;
				int upper = (a[i]+r[i])%360;
				if (upper >= lower && ang-eps <= upper && ang+eps >= lower) {
					g[i].push_back(j);
				} else if (lower > upper && (ang-eps <= upper || ang+eps >= lower)) {
					g[i].push_back(j);
				}
			}
		}
	}
	if (topsort()) {
		for (int i = 0; i < n; i++) {
			std::cout << l[i]+1 << " ";
		}
	} else {
		std::cout << "-1\n";
	}
}