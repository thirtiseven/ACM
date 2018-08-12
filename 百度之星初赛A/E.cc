#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;
int a[maxn], s[maxn];	
std::set<int> val;
std::set<int> in;
int n, k;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while (std::cin >> n >> k) {
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			s[i] = s[i-1] + a[i];
		}
		in.insert(0);
		in.insert(n+1);
		val.insert(s[n]-s[0]);
		int pos;
		for (int i = 0; i < n; i++) {
			std::cin >> pos;
			auto fin = in.upper_bound(pos);
			int r = *fin;
			fin--;
			int l = *fin;
			in.insert(pos);
			auto ans = val.lower_bound(k);
			int ans1 = *ans;
			ans--;
			int ans2 = *ans;
			std::cout << ans1 << " " << ans2 << '\n';
			std::cout << std::min(std::abs(k-ans1), std::abs(k-ans2)) << '\n';
			val.erase(s[r-1]-s[l]);
			if (r-1!=pos) val.insert(s[r-1]-s[pos]);
			if (pos-1!=r) val.insert(s[pos-1]-s[l]);
//			std::cout << l << " " << r << '\n';
		}
	}
}