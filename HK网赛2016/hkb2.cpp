#include <algorithm>
#include <cstring>
#include <string.h>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>

#define N 200005

using namespace std;

int n;
int belong[N];        //belong[i]表示箱子i在箱子belong[i]里面
int qnum;             //查询次数
int m;
int q[25];
vector<int> vec[N];				   //一棵树
int DFN[N];                       // 每个节点DFS到的顺序编号DFN[i]
pair<int,int> range[N];           //range[i]表示箱子i包含的箱子的DFN编号范围
int tot[N];                       //tot[i]表示箱子i包含的箱子总数（包括箱子i本身
int pos;
int contain[N];


void dfs(int u){         		  //DFS遍历树
	DFN[u] = pos++;
	range[u].first = pos;
	tot[u] = 1;
	for(int i = 0; i < vec[u].size(); i++){
		int v = vec[u][i];
		dfs(v);
		tot[u] += tot[v];
	}
	range[u].second = pos;
}

int doesBBelongA(int a,int b){
	while(belong[b] != belong[0]){
//		cout << "circle" << endl;
		if(belong[b] == a){
			return 1;
		}else{
			b = belong[b];
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	while(cin >> n){								//输入盒子总数
		pos = 0;
		memset(tot , 0 , sizeof(tot));
		for(int i = 1; i <= n; i++){
			vec[i].clear();
		}
		for(int i = 1; i <= n; i++){
			cin >> belong[i];
			vec[belong[i]].push_back(i);
		}
//		for(int i = 1; i <= n; i++){
//			cout << belong[i];
//		}
		dfs(0);       //从根节点0开始遍历
		cin >> qnum;
		while(qnum--){
			cin >> m;
			for(int i = 0;i < m;i++){
				cin >> q[i];                	//q数组为查询的箱子集合
			}
		//	sort(q,q+m);
			int flag[N];
			memset(flag , 0 , sizeof(flag));
			if(m > 1){
				for (int i = 0; i < m; i++){
					for(int j = i + 1; j < m; j++){
	//					cout << q[i] << q[j] << ' ';
	//					cout << doesBBelongA(q[i], q[j]) << endl;
						if(doesBBelongA(q[i], q[j])){
							flag[q[j]] = 1;
							break;
						}
					}
				}
			}
			int ret = 0;
			for (int i = 0; i < m; i++){
				if(flag[q[i]] == 0){  		//箱子q[i]没被其他箱子包含
					ret += tot[q[i]];
				}
			}
			cout << ret << endl;
		}
	}
	return 0;
}