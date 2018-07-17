#include <iostream>
#include <fstream>

std::ofstream fout ("oo.txt"); 
std::ifstream fin ("ii.txt"); 
using ll = long long int;

void solve() {
	std::string s[51];
	ll n, k, v;
	fin >> n >> k >> v;
	for (int i = 0; i < n; i++) {
		fin >> s[i];
	}
	int now = (k*(v-1))%n;
	if (now+k-1<n) {
		for (int i = 0; i < k; i++) {
			fout << " " << s[now+i];
//			std::cout << s[now+i] << " ";
		}
	} else {
		for (int i = 0; i < now+k-n; i++) {
			fout << " " << s[i];
//			std::cout << s[i] << " ";
		}
		for (int i = 0; now+i<n; i++) {
			fout << " " << s[now+i];
//			std::cout << s[now+i] << " ";
		}
 	}
	std::cout << '\n';
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	int T;
	fin >> T;
	for (int i = 1; i <= T; i++) {
		fout << "Case #" << i << ":";
		solve();
		fout << '\n';
	}
}