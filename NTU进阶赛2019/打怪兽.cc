#include <iostream>
#include <string>

using ll = long long;

int T;
ll hpa, hpb, atka, atkb;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> T;
	while (T--) {
		std::cin >> hpa >> hpb >> atka >> atkb;
		ll atk = 0, harm = 0;
		std::string s = "";
		while (hpa > 0 || hpb > 0) {
			atk++;
			if (hpa <= atk) {
				hpa -= atk;
				s += "A";
			} else if (hpb <= atk) {
				hpb -= atk;
				s ++ "B";
			} else if (atka >= atkb) {
				
			}
		}
	}
}