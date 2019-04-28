#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 100011
long long manhigh[maxn], manlow[maxn], ladyhigh[maxn], ladylow[maxn];
int flag, flag1, flag2, flag3, flag4;
using namespace std;
struct people
{
	long long len;
	bool pre;
}gen[maxn], lady[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		flag = flag1 = flag2 = flag3 = flag4 = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> gen[i].len;
		}
		for(int i = 0; i < m; i++)
		{
			cin >> lady[i].len;
		}
		for(int i = 0; i < n; i++)
		{
			cin >> gen[i].pre;
		}
		for(int i = 0; i < m; i++)
		{
			cin >> lady[i].pre;
		}
		for(int i = 0; i < n; i++)
		{
			if(gen[i].pre)
			{
				manhigh[flag1++] = gen[i].len;
			}
			else
			{
				manlow[flag2++] = gen[i].len;
			}
		}
		for(int i = 0; i < m; i++)
		{
			if(lady[i].pre)
			{
				ladyhigh[flag3++] = lady[i].len;
			}
			else
			{
				ladylow[flag4++] = lady[i].len;
			}
		}
		sort(manhigh, manhigh + flag1, cmp);
		sort(manlow, manlow + flag2, cmp);
		sort(ladyhigh, ladyhigh + flag3, cmp);
		sort(ladylow, ladylow + flag4, cmp);
		for(int i = 0; i < flag1; i++)
		{
			cout << manhigh[i];
		}
		for(int i = 0; i < flag1; i++)
		{
			int ok = 0;
			for(int j = 0; j < flag2; j++)
			{
				if(manhigh[i] < ladylow[j] && manhigh[i] >= 0 && ladylow[i] >= 0)
				{
					flag += 1;
					manhigh[i] = -1;
					ladylow[j] = -1;
					ok = 1;
				}
				if(ok)
				{
					break;
				}
			}
		}
		for(int i = 0; i < flag3; i++)
		{
			int ok = 0;
			for(int j = 0; j < flag4; j++)
			{
				if(manlow[i] < ladyhigh[j] && manlow[i] >= 0 && ladyhigh[i] >= 0)
				{
					flag += 1;
					manlow[i] = -1;
					ladyhigh[j] = -1;
					ok = 1;
				}
				if(ok)
				{
					break;
				}
			}
		}
		cout << flag << endl;
	}
	return 0;
}