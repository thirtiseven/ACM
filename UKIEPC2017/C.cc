#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, red = 0, maxx = 0, left = 0;
	std::string s;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> s;
		if(s == "red") red++;
		else if(s == "yellow") {maxx = std::max(maxx, 2);left+=2;}
		else if(s == "green") {maxx = std::max(maxx, 3);left+=3;}
		else if(s == "brown") {maxx = std::max(maxx, 4);left+=4;}
		else if(s == "blue") {maxx = std::max(maxx, 5);left+=5;}
		else if(s == "pink") {maxx = std::max(maxx, 6);left+=6;}
		else if(s == "black") {maxx = std::max(maxx, 7);left+=7;}
	}
	int ans;
	if(n == 1) {
		ans = std::max(left, 1);
	} else if(maxx == 0){
		ans = 1;
	} else {
		ans = red*(1+maxx)+left;
	}
	std::cout << ans << std::endl;
	return 0;
}