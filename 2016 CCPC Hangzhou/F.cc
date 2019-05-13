#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int T;
	std::string s;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> s;
		long long ans = -1e18;
		for (int i = 2; i <= s.length()-3; i++) {
			long long cur = 0;
			cur = std::max(std::stoll(s.substr(0, 1))+std::stoll(s.substr(1, i-1)), std::stoll(s.substr(0, i-1))+std::stoll(s.substr(i-1, 1)));
			
			cur -= std::stoll(s.substr(i,1)) * std::stoll(s.substr(i+1,1)) / std::stoll(s.substr(i+2));
//			std::cout << s.substr(0, 1) << " " << std::stoll(s.substr(1, i-1)) << " " << std::stoll(s.substr(0, i-1)) << " "
//				<< std::stoll(s.substr(i-1, 1)) << " " << std::stoll(s.substr(i,1)) << " " << std::stoll(s.substr(i+1,1)) << " "
//				<< std::stoll(s.substr(i+2)) << '\n';
			ans = std::max(cur, ans);
		}
		std::cout << "Case #" << CAS << ": " <<  ans << '\n';
	}
}