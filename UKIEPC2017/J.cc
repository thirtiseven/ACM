#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]) {  
	int N;
	long double t, ans = 0;
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> t;
		if(t == 0) ans += 2;
		else
		ans += 1.0/t;
		//std::cout << ans << '\n';
	}
	std::cout << std::fixed << std::setprecision(6) << ans << std::endl;
	return 0;
}