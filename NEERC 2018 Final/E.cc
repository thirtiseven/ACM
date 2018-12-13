#include <iostream>
#include <string>

std::string ans[70] = {	"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", 
						"b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1", 
						"c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", 
						"d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1", 
						"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", 
						"f8", "f7", "f6", "f5", "f4", "f3", "f2", "f1", 
						"g1", "h1", "h2", "g2", "g3", "h3", "h4", "g4", 
						"g5", "h5", "h6", "g6", "g7", "h7", "h8"
						};
						
std::string ans2[70] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", 
						"b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1", 
						"c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", 
						"d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1", 
						"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", 
						"f8", "f7", "f6", "f5", "f4", "f3", "f2", "f1", 
						"g1", "h1", "h2", "g2", "g3", "h3", "h4", "g4", 
						"g8", "g5", "h5", "h6", "g6", "g7", "h7", "h8"
						};

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if (n == 63) {
		for (int i = 0; i < 63; i++) {
			std::cout << ans2[i] << " ";
		}
		std::cout << ans2[63];
		exit(0);
	}
	for (int i = 0; i < n-1; i++) {
		std::cout << ans[i] << " ";
	}
	if (ans[n-2][0] == 'g' || ans[n-2][1] == '8') {
		std::cout << "g8 h8";
	} else if (ans[n-2][0] == 'h') {
		std::cout << "h7 h8";
	} else {
		std::cout << "h" << ans[n-2][1] << " " << "h8";
	}
}