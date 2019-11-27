#include <iostream>
#include <string>
#include <queue>
#include <vector>

const int maxn = 700;
const int INF = 0x3f3f3f3f;

int T, r, c;
std::vector<std::string> s;
int n, m, startX, startY, endX, endY;
int vis[maxn][maxn];
int DX[6] = {1, 1, -1, -1, 2, -2};
int DY[6] = {3, -3, 3, -3, 0, 0};
struct Status {
	int X, Y, Step;
};

int bfs() {
	std::queue<Status> Que;
	Que.push(Status {startX, startY, 1});
	vis[startX][startY] = 0;
	while (!Que.empty()) {
		Status Cur = Que.front(); Que.pop();
		if (Cur.X == endX && Cur.Y == endY) {
			return Cur.Step;
		}
		for (int i = 0; i < 6; ++i) {
			int NX = Cur.X + DX[i], NY = Cur.Y + DY[i];
			if (NX >= 0 && NX < n && NY >= 0 && NY < m && s[NX][NY] == ' ') {
				int NNX = NX + DX[i], NNY = NY + DY[i];
				if (NNX >= 0 && NNX < n && NNY >= 0 && NNY < m && Cur.Step + 1 < vis[NNX][NNY]) {
					Que.push(Status {NNX, NNY, Cur.Step + 1});
					vis[NNX][NNY] = Cur.Step + 1;
				}
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> r >> c;
		std::cin.get();
		n = 4*r+3, m = 6*c+3;
		for (int i = 0; i < n; i++) {
			std::string x;
			std::getline(std::cin, x);
			s.push_back(std::move(x));
			for (int j = 0; j < m; ++j) {
				vis[i][j] = INF;
				if (s[i][j] == 'S') {
					startX = i; 
					startY = j;
				}
				if (s[i][j] == 'T') {
					endX = i; 
					endY = j;
				}
			}
		}
		std::cout << bfs() << '\n';
	}
} 