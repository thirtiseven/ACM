#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int T;
	std::string s, ans1, ans2;
	int k;
	std::cin >> T;
	while (T--) {
		std::cin >> s >> k;
		ans1 = ans2 = s;
		int aa= k;
		for (int i = 0; i < aa; i++) {
			if (i >= s.length()) break;
			char minn = ans1[i];
			int mi = i;
			for (int j = i; j < s.length(); j++) {
				minn = std::min(minn, ans1[i]);
				if (ans1[j] <= minn) {
					minn = ans1[j];
					mi = j;
				}
			}
			if (ans1[i] == ans1[mi]) aa++;
			std::swap(ans1[i], ans1[mi]);
		}
		aa = k;
		for (int i = 0; i < aa; i++) {
			if (i >= s.length()) break;
			char maxx = ans2[i];
			int ma = i;
			for (int j = i; j < s.length(); j++) {
				maxx = std::max(maxx, ans2[i]);
				if (ans2[j] >= maxx) {
					maxx = ans2[j];
					ma = j;
				}
			}
			if (ans2[i] == ans2[ma]) aa++;
			std::swap(ans2[i], ans2[ma]);
//			std::cout << i << " " << maxx  << " " << ma << " " << aa << " " << ans2 << '\n';
		}
		std::cout << ans1 << " " << ans2 << '\n';
	}
}