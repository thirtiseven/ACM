#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) {  
	bool daylight[1825100];
	memset(daylight, 0, sizeof(daylight));
	int n, h, r, t;
	int maxh = -1;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> h >> r >> t;
		maxh = std::max(maxh, h);
		for(int j = 0; j <= 182511; j += h) {
			if(r < t){
				for(int k = j+r+1; k < j+t; k++) {
					daylight[k] = true;
					//std::cout << k;
				}
			} else {
				for(int k = j+1; k < j+t; k++) {
					daylight[k] = true;
					//std::cout << k;
				}
				for(int k = j+r; k <= j+h; k++) {
					daylight[k] = true;
					//std::cout << k;
				}
			}
		}
		//std::cout << "\n";
	}
	//for(int i = 0; i < 30; i++) {
		//std::cout << daylight[i] << " ";
	//}
	for(int i = 1; i <= 1850*maxh; i++) {
		if(!daylight[i]) {
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << "impossible\n";
	return 0;
}