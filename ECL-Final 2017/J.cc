#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
int c[maxn], minn[maxn], maxx[maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		std::fill(minn, minn+maxn, 0);
		std::fill(maxx, maxx+maxn, 0);
		bool yes = 1;
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> c[i];
			int news1 = std::max(c[i] - maxx[i], 0);
			int news2 = std::max(c[i] - minn[i], 0);
			if (news2) {
				for (int j = 1; j < 5; j++) {
					maxx[i+j] += news1;
				}
				for (int j = 1; j < 3; j++) {
					minn[i+j] += news2;
				}
			}
			if (c[i] < minn[i]) {
				yes = 0;
			}
		}
		for (int i = n; i < n+5; i++) {
			if (minn[i] > 0) {
				yes = 0;
				break;
			}
		}
		std::cout << "Case #" << tt << ": " << (yes?"Yes\n":"No\n");	
	}
}