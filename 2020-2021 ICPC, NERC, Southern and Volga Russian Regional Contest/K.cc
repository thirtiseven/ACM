#include <iostream>
#include <algorithm>
#include <string>
#include <set>

int T;
std::string s;
std::set<std::pair<int, int>> st;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		st.clear();
		std::cin >> s;
		int x = 0, y = 0;
		bool find = 0;
		for (int i = 0; i < s.length(); i++) {
			int xx = x, yy = y;
			int obx = x, oby = y;
			if (s[i] == 'U') oby++;
			if (s[i] == 'D') oby--;
			if (s[i] == 'L') obx--;
			if (s[i] == 'R') obx++;
			if (st.count(std::make_pair(obx, oby)) == 0) {
				for (int j = i+1; j < s.length(); j++) {
					int xxx = x, yyy = y;
					if (s[j] == 'U') y++;
					if (s[j] == 'D') y--;
					if (s[j] == 'L') x--;
					if (s[j] == 'R') x++;
					if (x == obx && y == oby) {
						x = xxx;
						y = yyy;
					}
				}
	//			std::cout << obx << ' ' << oby << ' ' << x << ' ' << y << '\n';
				if (x == 0 && y == 0) {
					find = 1;
					std::cout << obx << ' ' << oby << '\n';
					break;
				}
			}
			st.insert(std::make_pair(obx, oby));
			x = xx, y = yy;
			if (s[i] == 'U') y++;
			if (s[i] == 'D') y--;
			if (s[i] == 'L') x--;
			if (s[i] == 'R') x++;
		}
		if (!find && x == 0 && y == 0) {
			find = 1;
			std::cout << "100000000 100000000\n";
			continue;
		}
		if (!find) {
			std::cout << "0 0\n";
		}
	}
}