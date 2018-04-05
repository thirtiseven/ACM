#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

const int maxn = 123;
const long long inf = 100000000000;

struct planet{
	double x, y, z;
};

double dis(planet a, planet b) {
	return sqrt(std::abs(a.x - b.x)*std::abs(a.x - b.x)+std::abs(a.y - b.y)*std::abs(a.y - b.y)+std::abs(a.z - b.z)*std::abs(a.z - b.z));
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	int cnt = 1;
	while (T--) { 
		std::map<std::string, int> plist;
		std::map<int, std::string> nlist;
		int p, w, q;
		planet pp[maxn];
		double d[maxn][maxn];
		std::cin >> p;
		for(int i = 0; i < p; i++) {
			for(int j = 0; j < p; j++) {
				d[i][j] = inf;
			}
		}
		std::string tt, ee;
		for (int i = 0; i < p; i++) {
			std::cin >> tt;
			plist[tt] = i;
			nlist[i] = tt;
			std::cin >> pp[i].x >> pp[i].y >> pp[i].z;
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				d[i][j] = dis(pp[i], pp[j]);
				d[j][i] = dis(pp[i], pp[j]);
			}
		}
		std::cin >> w;
		for (int i = 0; i < w; i++) {
			std::cin >> tt >> ee;
			d[plist[tt]][plist[ee]] = 0;
		}
		d[0][0] = 0;
		for(int k = 0; k < p; k++) {
			for(int i = 0; i < p; i++) {
				for(int j = 0; j < p; j++) {
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
				}
			}
		}
		std::cin >> q;
		std::cout << "Case " << cnt << ":\n";
		cnt++;
		for (int i = 0; i < q; i++) {
			std::cin >> tt >> ee;
			std::cout << "The distance from " << tt << " to " << ee << " is " << (long long)(d[plist[tt]][plist[ee]]+0.5) << " parsecs.\n";
		}
	}
}