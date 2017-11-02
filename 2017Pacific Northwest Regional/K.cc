#include <iostream>
#include <iomanip>
int a[10], b[10];

int main(int argc, char *argv[]) {
	for(int i = 0; i < 6; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < 6; i++) {
		std::cin >> b[i];
	}
	double cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			if(a[i] > b[j]) {
				cnt1++;
			}
			if(a[i] == b[j]) {
				cnt2++;
			}
		}
	}
	std::cout << std::fixed << std::setprecision(5) << cnt1*1.0/(36-cnt2) << std::endl;
	return 0;
}