#include <algorithm>
#include <iostream>
#include <set>

#define N 200005

using namespace std;

int n , k;
struct node{
	int bg,ed;
}a[N];

bool cmp(node a , node b){        //sort-cmp
	if(a.ed== b.ed) return a.bg < b.bg;
	return a.ed< b.ed;
}

int main(){
	cin >> n >> k;
		for (int i = 0 ; i < n ; ++i)
		cin >> a[i].bg >> a[i].ed;
		sort(a,a+n,cmp);							//按照结束时间排序
		multiset<int> endtime;         //multiset存放每个教室正在进行的活动的结束时间
		endtime.clear();
		int ans = 0;					//活动个数
		for (int i = 0 ; i < n ; i++){     //遍历每个活动
			multiset<int> :: iterator iter;   
			iter = endtime.lower_bound(-a[i].bg);          //是否存在某个教室的活动在i开始时间前前就结束了
			if (iter == endtime.end()){                  //如果没有在活动i开始前就结束活动的教室，就另找一个教室
				if (endtime.size() < k){
					endtime.insert(-a[i].ed- 1);
					ans++;
				}
				continue;
			}
			endtime.erase(iter);                    //找到了某个教室活动已经结束了，活动i在这个教室进行
			endtime.insert( - a[i].ed - 1);      //更新活动的结束时间
			ans++;
		}
	cout << ans << endl;
	return 0;
}