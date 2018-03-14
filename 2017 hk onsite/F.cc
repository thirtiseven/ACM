#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>

struct point {
	long long x, y;
	point() { };
};

int main(int argc, char *argv[]) {  
	int m, n;
	while (scanf("%d %d", &m, &n)) {
		point cost[1009], bike[1009];
		if (m==0 && n==0) {
			break;
		}
//		printf("%d %d", m, n);
		std::string temp;
		getchar();
		for (int i = 0; i < m; i++) {
			std::cin >> temp;
			int pos;
			for (int b = 0; b < temp.length(); b++) {
				if(temp[b] == ',') pos = b;
			}
			bike[i].x = stoll(temp.substr(1,pos-1));
			bike[i].y = stoll(temp.substr(pos+1,temp.length()-pos));
		}
		for (int i = 0; i < n; i++) {
			std::cin >> temp;
			int pos;
			for (int b = 0; b < temp.length(); b++) {
				if(temp[b] == ',') pos = b;
			}
			cost[i].x = stoll(temp.substr(1,pos-1));
			cost[i].y = stoll(temp.substr(pos+1,temp.length()-pos));
		}
		long long s[1009];
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; i++) {
			scanf("%lld", &s[i]);
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if ( (cost[i].x - bike[j].x)*(cost[i].x - bike[j].x) + (cost[i].y - bike[j].y)*(cost[i].y - bike[j].y) <= s[i] * s[i] ) {
					cnt++;
				}
			}
		std::cout << cnt << (i!=n-1?" ":"\n");
		}
	}	
	return 0;
}