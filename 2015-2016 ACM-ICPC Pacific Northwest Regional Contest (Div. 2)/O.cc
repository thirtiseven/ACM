#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define maxn 510

int n, m, g[maxn][maxn], dir[4][2] = {0,1,0,-1,1,0,-1,0};
std::string s;
bool vis[maxn][maxn];

struct Node{
	int x, y, cnt, len;
	Node(int _x, int _y, int _len, int _cnt){
		x = _x; y = _y; len = _len; cnt = _cnt;
	}
};

bool judge(int x, int y){
	if(x < 1 || x > n || y < 1 || y > m || vis[x][y])   return false;
	return true;
}

void bfs(){
	std::queue<Node> Q;
	memset(vis, 0, sizeof(vis));
	Q.push(Node(1, 1, g[1][1], 0));
	vis[1][1] = true;
	while(!Q.empty()){
		Node h = Q.front();
		Q.pop();
		int xx = h.x, yy = h.y, lenn = h.len, cntt = h.cnt;
		if(xx == n && yy == m){
			std::cout << cntt << std::endl;
			return;
		}
		for(int i = 0; i <= 3; i++){
			int xi = xx+dir[i][0]*lenn, yi = yy+dir[i][1]*lenn;
			if(judge(xi, yi)){
				vis[xi][yi] = true;
				Q.push(Node(xi, yi, g[xi][yi], cntt+1));
			}
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;
	return ;
}

int main(int argc, char *argv[]) { 
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++){
		std::cin >> s;
		for(int j = 0; j < m; j++)  {
			g[i][j+1] = (s[j]-'0');
		}
	}
	bfs();
	return 0;
}