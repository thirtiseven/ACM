#include <iostream>
#include <cmath>
#include <algorithm>
#define accept 0.01
#define pi 3.1415926

struct point {
	double x, y;
	double a, s;
};

double dis2(point m, point n) {
	return pow(m.x - n.x, 2) + pow(m.y - n.y, 2);
}

double dis(point m, point n) {
	return sqrt(pow(m.x - n.x, 2) + pow(m.y - n.y, 2));
}

int main(int argc, char *argv[]) {  
	int t;
	std::cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		int node_num;
		std::cin >> node_num;
		if(node_num == 3 || node_num == 4) {
			int rubbish;
			for(int i = 0; i < 2 * node_num; i++) {
				std::cin >> rubbish;
			}
			std::cout << "Case #" << cas << ": " << "YES" << std::endl;
			continue;
		}
		if(node_num > 6) {
			int rubbish;
			for(int i = 0; i < 2 * node_num; i++) {
				std::cin >> rubbish;
			}
			std::cout << "Case #" << cas << ": " << "NO" << std::endl;
			continue;
		}
		bool flag = 0;
		if(node_num == 6) {
			point p[7];
			for(int i = 0; i < 6; i++) {
				std::cin >> p[i].x >> p[i].y;
			}
			for(int i = 1; i < 6; i++) {
				p[i].s = dis(p[i], p[i-1]);
			}
			p[0].s = dis(p[0], p[5]);
			p[5].a = acos((p[0].s * p[0].s + p[5].s * p[5].s - dis2(p[0], p[4])) / 2 * p[0].s * p[5].s);
			p[0].a = acos((p[0].s * p[0].s + p[1].s * p[1].s - dis2(p[1], p[5])) / 2 * p[0].s * p[1].s);
			for(int i = 1; i < 5; i++) {
				p[i].a = acos((p[i].s * p[i].s + p[i+1].s * p[i+1].s - dis2(p[i-1], p[i+1])) / 2 * p[i].s * p[i+1].s);
			}
			flag = 1;
			for(int i = 0; i < 5; i++) {
				if(fabs(p[i].s - p[5].s) < accept) {
					flag = 0;
					break;
				}
			}
			if(flag == 1) {
				break;
			}
			for(int add = 0; add < 6; add++) {
				if(p[(1+add)%6].s == p[(4+add)%6].s && 
				   fabs(p[(1+add)%6].a + p[(2+add)%6].a + p[(3+add)%6].a - 2 * pi) < accept) {
					flag = 1;
					goto out6;
				}
				if(p[(1+add)%6].s == p[(4+add)%6].s && 
				   p[(3+add)%6].s == p[(5+add)%6].s && 
				   fabs(p[(1+add)%6].a + p[(2+add)%6].a + p[(4+add)%6].a - 2 * pi) < accept) {
					flag = 1;
					goto out6;
				}
				if (p[(0+add)%6].s == p[(5+add)%6].s && 
				    p[(1+add)%6].s == p[(2+add)%6].s && 
				    p[(3+add)%6].s == p[(4+add)%6].s && 
				    fabs(p[(1+add)%6].a - pi/3.0) < accept &&
					fabs(p[(3+add)%6].a - pi/3.0) < accept &&
					fabs(p[(5+add)%6].a - pi/3.0) < accept
				   ) {
					flag = 1;
					goto out6;
				}		
			}
		}
		out6:
		if(node_num == 5) {
			point p[6];
			for(int i = 0; i < 5; i++) {
				std::cin >> p[i].x >> p[i].y;
			}
			for(int i = 1; i < 5; i++) {
				p[i].s = dis(p[i], p[i-1]);
			}
			p[0].s = dis(p[0], p[4]);
			p[4].a = acos((p[0].s * p[0].s + p[4].s * p[4].s - dis2(p[0], p[3])) / 2 * p[0].s * p[4].s);
			p[0].a = acos((p[0].s * p[0].s + p[1].s * p[1].s - dis2(p[1], p[4])) / 2 * p[0].s * p[1].s);
			for(int i = 1; i < 4; i++) {
				p[i].a = acos((p[i].s * p[i].s + p[i+1].s * p[i+1].s - dis2(p[i-1], p[i+1])) / 2 * p[i].s * p[i+1].s);
			}
			
			for(int add = 0; add < 5; add++) {
				if (fabs(p[(1+add)%5].a + p[(2+add)%5].a - pi) < accept &&
					fabs(p[(0+add)%5].a + p[(3+add)%5].a + p[(4+add)%5].a - pi) < accept) {
					flag = 1;
					goto out5;
				}
				if (fabs(p[(1+add)%5].a + p[(3+add)%5].a) - pi < accept &&
					p[(2+add)%5].s == p[(4+add)%5].s) {
					flag = 1;
					goto out5;
				}
				if (p[(0+add)%5].s == p[(1+add)%5].s &&
					p[(3+add)%5].s == p[(2+add)%5].s + p[(4+add)%5].s && 
					fabs(p[(0+add)%5].a - 2.0*pi/3.0) < accept &&
					fabs(p[(2+add)%5].a - 2.0*pi/3.0) < accept &&
					fabs(p[(3+add)%5].a - 2.0*pi/3.0) < accept) {
					flag = 1;
					goto out5;	
				}
				if (p[(1+add)%5].s == p[(2+add)%5].s &&
					p[(3+add)%5].s == p[(4+add)%5].s && 
					fabs(p[(1+add)%5].a - pi/2.0) < accept &&
					fabs(p[(3+add)%5].a - pi/2.0) < accept) {
					flag = 1;
					goto out5;
				}
			}
			
		}
		out5:
		if(flag) {
			std::cout << "Case #" << cas << ": " << "YES" << std::endl;
		} else {
			std::cout << "Case #" << cas << ": " << "NO" << std::endl;
		}
	}
	return 0;
}