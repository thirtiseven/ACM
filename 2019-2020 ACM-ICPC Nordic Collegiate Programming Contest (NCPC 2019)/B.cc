#include <iostream>

using ll = long long;

ll ax, ay, bx, by, cx, cy;

ll ans;

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	while (t--) {
		ans = 9e18+3;
		std::cin >> ax >> ay >> bx >> by >> cx >> cy;
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(cx, cy);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(bx, by);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(cx, cy);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(ax, ay);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(cx, cy);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(bx, by);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(cx, cy);
		ans = std::min(ans, (ax+bx+cx)*std::max(std::max(ay, by), cy));
		std::swap(ax, ay);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		std::swap(bx, cx);
		std::swap(by, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		std::swap(bx, ax);
		std::swap(by, ay);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(bx, by);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(cx, cy);
		ans = std::min(ans, std::max(ay, by+cy) * (ax+std::max(bx, cx)));
		ans = std::min(ans, std::max(by, ay+cy) * (bx+std::max(ax, cx)));
		ans = std::min(ans, std::max(ax + bx, cx) * (std::max(ay, by) + cy));
		std::swap(ax, ay);
		std::cout << ans << '\n';
	}
}