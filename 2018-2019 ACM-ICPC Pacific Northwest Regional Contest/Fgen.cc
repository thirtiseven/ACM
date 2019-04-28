#include <iostream>
#include <fstream>
#include <random>

std::ofstream fout ("in.txt"); 

std::mt19937 gen(37);
const int mod = 1e4;

int main(int argc, char *argv[]) { 
	fout << 5 << '\n';
	for (int i = 0; i < 5; i++) {
		fout << gen() << " " << gen() << " " << gen() << " " << gen() << '\n';
	}
}