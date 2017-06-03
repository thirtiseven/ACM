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
		dfs(0);       //从根节点0开始遍历
		cin >> qnum;
		while(qnum--){
			cin >> m;
			for(int i = 0;i < m;i++){
				cin >> q[i];                	//q数组为查询的箱子集合
			}
			int flag = 0;               	    //用flag来记录哪些箱子被删掉了，如果(flag&(1<<i))，箱子q[i]就被删掉了。
			for (int i = 0; i < m; i++){   	    //暴力枚举每个箱子q[i]，看是否包含在另一个箱子里面
				if(!(flag & (1 << i))){
					for(int j = i + 1; j < m; j++){
						if(!(flag & (1 << j))){
							if (range[q[i]].first <= range[q[j]].first && range[q[i]].second >= range[q[j]].second){          //箱子q[j]包含在箱子q[i]里面
								flag |= (1 << j);
							}else if (range[q[j]].first<=range[q[i]].first && range[q[j]].second >= range[q[i]].second){      //箱子q[i]包含在箱子q[j]里面
								flag |= (1 << i);
								break;
							}
						}
					}
				}
			}
			int ret = 0;
			for (int i = 0; i < m; i++){
				if(!(flag & (1 << i))){     //箱子q[i]没被其他箱子包含
					ret += tot[q[i]];
				}
			}
			cout << ret << endl;
		}
	}
	return 0;
}