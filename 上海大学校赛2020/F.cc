#include <iostream>

int zeller(int y, int m, int d) {
	if (m==1 || m==2) {
		m += 12, y = y-1;
	}
	int w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
	return (w%7+7)%7;
}

int T, y, m, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> y >> m >> d;
		int fa = 1, mo = 1;
		int cnt = 0;
		for (int i = 1; i <= 31; i++) {
			if (zeller(y, 5, i) == 0) {
				cnt++;
			}
			if (cnt == 2) {
				mo = i;
				break;
			}
		}
		cnt = 0;
		for (int i = 1; i <= 30; i++) {
			if (zeller(y, 6, i) == 0) {
				cnt++;
			}
			if (cnt == 3) {
				fa = i;
				break;
			}
		}
		if (m < 5 || (m==5 && d < mo)) {
			if (mo%10 == 1 && mo != 11) {
				std::cout << "Mother's Day: May " << mo << "st, " << y << '\n';
			} else if (mo%10 == 2 && mo != 12) {
				std::cout << "Mother's Day: May " << mo << "nd, " << y << '\n';
			} else if (mo%10 == 3 && mo != 13) {
				std::cout << "Mother's Day: May " << mo << "rd, " << y << '\n';
			} else {
				std::cout << "Mother's Day: May " << mo << "th, " << y << '\n';
			}
		} else if (m < 6 || (m==6 && d < fa)) {
			if (fa%10 == 1 && fa != 11) {
				std::cout << "Father's Day: June " << fa << "st, " << y << '\n';
			} else if (fa%10 == 2 && fa != 12) {
				std::cout << "Father's Day: June " << fa << "nd, " << y << '\n';
			} else if (fa%10 == 3 && fa != 13) {
				std::cout << "Father's Day: June " << fa << "rd, " << y << '\n';
			} else {
				std::cout << "Father's Day: June " << fa << "th, " << y << '\n';
			}
		} else {
			cnt = 0;
			for (int i = 1; i <= 31; i++) {
				if (zeller(y+1, 5, i) == 0) {
					cnt++;
				}
				if (cnt == 2) {
					mo = i;
					break;
				}
			}
			if (mo%10 == 1 && mo != 11) {
				std::cout << "Mother's Day: May " << mo << "st, " << y+1 << '\n';
			} else if (mo%10 == 2 && mo != 12) {
				std::cout << "Mother's Day: May " << mo << "nd, " << y+1 << '\n';
			} else if (mo%10 == 3 && mo != 13) {
				std::cout << "Mother's Day: May " << mo << "rd, " << y+1 << '\n';
			} else {
				std::cout << "Mother's Day: May " << mo << "th, " << y+1 << '\n';
			}
		}
	}
}