#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b, c, w, h,aa,bb,cc;
	std::cin >> aa >> bb >> cc >> w >> h;
	bool yes = 0;
	a = aa, b = bb, c = cc;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = bb, b = cc, c = aa;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = cc, b = aa, c = bb;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = aa, b = cc, c = bb;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = cc, b = bb, c = aa;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = bb, b = aa, c = cc;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	std::swap(w, h);
	
	a = aa, b = bb, c = cc;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = bb, b = cc, c = aa;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = cc, b = aa, c = bb;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = aa, b = cc, c = bb;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = cc, b = bb, c = aa;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	a = bb, b = aa, c = cc;
	if (a+2*c <= w && 2*c+2*b <= h) {
		yes = 1;
	}
	if (2*a+b+c <= w && a+b+c <= h) {
		yes = 1;
	}
	if (3*b+a+c <= w && a+c <= h) {
		yes = 1;
	}
	if (2*b+a+c <= w && 2*a+c <= h) {
		yes = 1;
	}
	
	if (yes == 1) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}