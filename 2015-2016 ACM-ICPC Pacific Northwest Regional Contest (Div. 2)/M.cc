#include <iostream>
#include <string>
#include <set>

int main(int argc, char *argv[]) {  
	int num, T;
	std::string s;
	std::cin >> T;
	double ans[110];
	bool yes[110];
	for(int i = 1; i < 101; i++) {
		ans[i] = i;
		yes[i] = 1;
	}
	while(T--) {
		std::cin >> s >> num;
		for(int i = 1; i < 101; i++) {
			//std::cout << s[0];
			if(s[0] == 'A') {
				ans[i] += num;
			} else if(s[0] == 'S') {
				//std::cout << "boom!\n";
				ans[i] -= num;
			} else if(s[0] == 'M') {
				ans[i] *= num;
			} else if(s[0] == 'D') {
				ans[i] = ans[i]/(double)num;
			}
			if(ans[i] < 0 || ans[i] != (int)ans[i]) {
				yes[i] = 0;
				//std::cout << "boom!\n";
			}
		}
	}
	int tot = 0;
	for(int i = 1; i < 101; i++) {
		if(!yes[i]) {
			tot++;
		}
	}
	std::cout << tot << std::endl;
	return 0;
}