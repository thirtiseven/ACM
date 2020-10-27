#include <iostream>
#include <algorithm>
#include <string>
#include <map>

std::string card[8];
std::pair<int, int> c[8];
std::map<char, int> mp;

int countnum(int n) {
	int res = 0;
	for (int i = 0; i < 7; i++) {
		if (c[i].first == n) {
			res++;
		}
	}
	return res;
}

int countcol(int n) {
	int res = 0;
	for (int i = 0; i < 7; i++) {
		if (c[i].second == n) {
			res++;
		}
	}
	return res;
}

bool findcard(int n, int m) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		n = 13;
	}
	for (int i = 0; i < 7; i++) {
		if (c[i].first == n && c[i].second == m) {
			return 1;
		}
	}
	return 0;
}

bool tonghuashun() {
	for (int i = 0; i < 7; i++) {
		bool yes = 1;
		for (int j = 1; j < 5; j++) {
			if (!findcard(c[i].first-j, c[i].second)) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			return 1;
		}
	}
	return 0;
}

bool sitiao() {
	for (int i = 1; i < 14; i++) {
		if (countnum(i) >= 4) {
			return 1;
		}
	}
	return 0;
}

bool hulu() {
	int yes1 = 0, yes2 = 0;
	for (int i = 1; i < 14; i++) {
		int temp = countnum(i);
		if (temp >= 3) {
			yes1++;
		} else if (temp == 2) {
			yes2++;
		}
	}
	if (yes1 >= 2 || (yes1 > 0 && yes2 > 0)) {
		return 1;
	}
	return 0;
}

bool tonghua() {
	for (int i = 1; i <= 4; i++) {
		if (countcol(i) >= 5) {
			return 1;
		}
	}
	return 0;
}

bool shunzi() {
	for (int i = 0; i < 7; i++) {
		bool yes = 1;
		for (int j = 1; j < 5; j++) {
			if (!countnum(c[i].first-j)) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			return 1;
		}
	}
	return 0;
}

bool santiao() {
	for (int i = 1; i < 14; i++) {
		if (countnum(i) >= 3) {
			return 1;
		}
	}
	return 0;
}

bool liangdui() {
	int yes1 = 0;
	for (int i = 1; i < 14; i++) {
		int temp = countnum(i);
		if (temp >= 2) {
			yes1++;
		}
	}
	if (yes1 >= 2) {
		return 1;
	}
	return 0;
}

bool yidui() {
	for (int i = 1; i < 14; i++) {
		int temp = countnum(i);
		if (temp >= 2) {
			return 1;
		}
	}
	return 0;
}

void init() {
	mp['2'] = 1; mp['3'] = 2; mp['4'] = 3; mp['5'] = 4; mp['6'] = 5;
	mp['7'] = 6; mp['8'] = 7; mp['9'] = 8; mp['T'] = 9; mp['J'] = 10;
	mp['Q'] = 11;mp['K'] = 12;mp['A'] = 13;
	mp['c'] = 1; mp['d'] = 2; mp['h'] = 3; mp['s'] = 4;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	init();
	for (int i = 0; i < 7; i++) {
		std::cin >> card[i];
		c[i] = std::make_pair(mp[card[i][0]], mp[card[i][1]]);
	}
	std::sort(c, c+7);
	if (tonghuashun()) {
		std::cout << "Straight flush\n";
	} else if (sitiao()) {
		std::cout << "Four of a kind\n";
 	} else if (hulu()) {
		std::cout << "Full house\n";
	} else if (tonghua()) {
		std::cout << "Flush\n";
 	} else if (shunzi()) {
		std::cout << "Straight\n";	
	} else if (santiao()) {
		std::cout << "Three of a kind\n";
	} else if (liangdui()) {
		std::cout << "Two pair\n";
	} else if (yidui()) {
		std::cout << "One pair\n";
	} else {
		std::cout << "High card\n";
	}
}