#include <iostream>
#include <random>

#include <fstream>
std::ofstream fout ("text.txt"); 

int main(int argc, char *argv[]) {  
	std::mt19937 gen(30);
	int T = 10;
	fout << T << '\n';
	while (T--) {
		int n = 20;
		fout << n << '\n';
		for (int i = 0; i < n; i++) {
			fout << gen()%13 << " ";
		}
		fout << '\n';
	}
}