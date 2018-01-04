#include <iostream>
#include <algorithm> 
#include <set>

struct point {
	int x, y, z;
	bool operator < (const point &miao) const {
		if(this->x == miao.x) {
			if(this->y == miao.y) {
				return this->z < miao.z;
			}
			return this->y < miao.y;
		}
		return this->x < miao.x;
	}
}planet[5010];


int n;
std::set<point> aa;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	std::cin >> planet[0].x >> planet[0].y >> planet[0].z; 
	for(int i = 1; i < n; i++) {
		std::cin >> planet[i].x >> planet[i].y >> planet[i].z;
		planet[i].x -= planet[0].x;
		planet[i].y -= planet[0].y;
		planet[i].z -= planet[0].z;
	}
	planet[0].x = 0, planet[0].y = 0, planet[0].z = 0;
	for(int i = 1; i < n; i++) {
		int gcccd;
		if(planet[i].x == 0 && planet[i].y == 0) {
			gcccd = planet[i].z;
		} else if(planet[i].x == 0 && planet[i].z == 0) {
			gcccd = planet[i].y;
		} else if(planet[i].y == 0 && planet[i].z == 0) {
			gcccd = planet[i].x;
		} else if(planet[i].x == 0) {
			gcccd = std::__gcd(planet[i].y, planet[i].z);
		} else if(planet[i].y == 0) {
			gcccd = std::__gcd(planet[i].x, planet[i].z);
		} else if(planet[i].z == 0) {
			gcccd = std::__gcd(planet[i].x, planet[i].y);
		} else {
			gcccd = std::__gcd(std::__gcd(planet[i].x, planet[i].y), planet[i].z);
		}
		planet[i].x /= gcccd;
		planet[i].y /= gcccd;
		planet[i].z /= gcccd;
		if(planet[i].x < 0) {
			planet[i].x = -planet[i].x;
			planet[i].y = -planet[i].y;
			planet[i].z = -planet[i].z;
		}
		aa.insert(planet[i]);
	}
	std::cout << aa.size() << std::endl;
	return 0;
}