#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

const int maxn = 50;

std::vector<int> g[maxn];
int du[maxn], n, m, l[maxn];
std::map<std::string, int> id;
std::string name[maxn];
std::string s1[maxn], s2[maxn];

bool topsort() {
	std::fill(du, du+maxn, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			du[g[i][j]]++;
		}
	}
	int tot = 0;
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		if(!du[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		l[tot++] = x;
		for(int j = 0; j < g[x].size(); j++) {
			int t = g[x][j];
			du[t]--;
			if(!du[t]) {
				q.push(t);
			}
		}
	}
	if(tot == n) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	while (std::cin >> m) {
		for (int i = 0; i < maxn; i++) {
			g[i].clear();
			id.clear();
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			std::cin >> s1[i] >> s2[i]; 
		}
		bool yes = 1;
		for (int i = 0; i < m; i++) {
			if (id.find(s1[i]) == id.end()) {
				name[cnt] = s1[i]; 
				id[s1[i]] = cnt;
				cnt++;
			}
			if (id.find(s2[i]) == id.end()) {
				name[cnt] = s2[i]; 
				id[s2[i]] = cnt;
				cnt++;
			}
			g[id[s1[i]]].push_back(id[s2[i]]);
//			std::cout << id[s1[i]] << ' ' << id[s2[i]] << '\n';
			n = cnt;
			if (!topsort()) {
				std::cout << s1[i] << ' ' << s2[i] << '\n';
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "0\n";
		}
	}
}