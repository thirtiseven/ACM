#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	std::vector<std::string> latin(n);
	for (int i = 0; i < n; i++) {
		std::cin >> latin[i];
	}
}