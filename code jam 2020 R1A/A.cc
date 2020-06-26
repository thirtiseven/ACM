#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

const int maxn = 52;
int T, n;
std::string p[maxn], first, second;
std::vector<std::string> x;

std::string gao(std::string s) {
	std::string res = "";
	for (auto it: s) {
		if (it != '*') {
			res += it;
		}
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int _=1; _<=T;_++) {
		x.clear();
		first = "";
		second = "";
		std::cin >> n;
		int maxx1 = -1, maxx2 = -1;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
			if (p[i][0] != '*') for (int j = 0; j < p[i].length(); j++) {
//				std::cerr << "??1\n";
				if (p[i][j] == '*') {
					if (j > maxx1) {
						maxx1 = j;
//						std::cout << "!!!1\n";
						first = p[i].substr(0, j);						
					}
					break;
				}
			}
			if (p[i][p[i].length()-1] != '*') for (int j = p[i].length()-1; j >= 0; j--) {
//				std::cerr << "??2\n";
				if (p[i][j] == '*') {
//					std::cerr << int(p[i].length())-j-1 <<' '<< maxx2 << ' ' << (int(p[i].length())-j-1 > maxx2)<<'\n';
					if (int(p[i].length())-j-1 > maxx2) {
//						std::cerr << "!!!!!!!!\n";
						maxx2 = p[i].length()-j-1;
//						std::cout << "!!!2\n";
						second = p[i].substr(j+1);
					}
					break;
				}
			}
		}
//		std::cout << first << " - " << second << '\n';
		bool check = 1;
		for (int i = 0; i < n; i++) {
			if (p[i][0] == '*' && p[i][p[i].length()-1] == '*') {
				x.push_back(gao(p[i]));
				continue;
			}
			int aa = -1, bb = -1;
			if (p[i][0] == '*') aa = 0;
			if (p[i][p[i].length()-1] == '*') bb = p[i].length()-1;
			if (p[i][0] != '*') {
				for (int j = 0; j < p[i].length(); j++) {
					if (p[i][j] == '*') {
						aa = j;
						break;
					} else {
						if (p[i][j] != first[j]) {
//							std::cerr << "YE " << p[i] << ' ' << p[i][j] << ' ' << first[j] << '\n';
							check = 0;
							break;
						}
					}
				}
			}
			if (p[i][p[i].length()-1] != '*') {
				int len1 = p[i].length(), len2 = second.length();
				for (int j = 1; j <= p[i].length(); j++) {
					if (p[i][len1-j] == '*') {
						bb = len1-j;
						break;
					} else {
						if (p[i][len1-j] != second[len2-j]) {
//							std::cerr << "RE " << p[i] << ' ' << p[i][len1-j] << ' ' <<second[len2-j] << '\n';
							check = 0;
							break;
						}
					}
				}
			}
//			std::cerr << p[i].substr(aa, bb-aa+1) << '\n';
//			std::cout << i << ' ' << aa << ' ' << bb << ' ' << bb-aa+1 << '\n';
			if (aa!=-1 && bb!=-1 && bb-aa+1 >= 1) {
//				std::cerr << i << ' ' << gao(p[i].substr(aa, bb-aa+1)) << '\n';
				x.push_back(gao(p[i].substr(aa, bb-aa+1)));
			}
		}
		std::cout << "Case #" << _ << ": ";
		if (check == 0) {
			std::cout << "*\n";
		} else {
			std::cout << first;
			for (auto it: x) {
				std::cout << it;
			}
			std::cout << second << '\n';
		}
	}
}