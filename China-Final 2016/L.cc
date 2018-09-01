#include <iostream>
#include <vector>

struct sb{
	int a, b, c, d;
	sb(int a1 = 0, int b2 = 0, int c1 = 0, int d1 = 0) {
		a = a1;
		b = b2;
		c = c1;
		d = d1;
	}
};

std::vector<sb> g;

void dfs(int cnt,int a,int b,int c,int d){
	if(cnt == 1){
		dfs(cnt+1,a+3,b,c,d);
		dfs(cnt+1,a,b+3,c,d);
		dfs(cnt+1,a+1,b+1,c,d);
	}
	else if(cnt == 2){
		dfs(cnt+1,a+3,b,c,d);
		dfs(cnt+1,a,b,c+3,d);
		dfs(cnt+1,a+1,b,c+1,d);
	}
	else if(cnt == 3){
		dfs(cnt+1,a+3,b,c,d);
		dfs(cnt+1,a,b,c,d+3);
		dfs(cnt+1,a+1,b,c,d+1);
	}
	else if(cnt == 4){
		dfs(cnt+1,a,b+3,c,d);
		dfs(cnt+1,a,b,c+3,d);
		dfs(cnt+1,a,b+1,c+1,d);
	}
	else if(cnt == 5){
		dfs(cnt+1,a,b,c,d+3);
		dfs(cnt+1,a,b+3,c,d);
		dfs(cnt+1,a,b+1,c,d+1);
	}
	else if(cnt == 6){
		dfs(cnt+1,a,b,c,d+3);
		dfs(cnt+1,a,b,c+3,d);
		dfs(cnt+1,a,b,c+1,d+1);
	}
	else if(cnt == 7){
		sb oo = sb(a, b, c, d);
		g.push_back(oo);
		return;
	}
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	dfs(1, 0, 0, 0, 0);
	for (int CC = 1; CC <= T; CC++) {
		int a2, b2, c2, d2;
		std::cin >> a2 >> b2 >> c2 >> d2;
		sb q = sb(a2,b2,c2,d2);
		std::cout << "Case #" << CC << ": ";
		int now = 0;
		for (auto it: g) {
			if (it.a == a2 && it.b == b2 && it.c == c2 && it.d == d2) {
				now++;
			}
		}
		if (now == 1) {
			std::cout << "Yes\n";
		} else if (now > 1) {
			std::cout << "No\n";
		} else {
			std::cout << "Wrong Scoreboard\n";
		}
	}
}