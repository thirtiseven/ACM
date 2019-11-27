#include<bits/stdc++.h>
using namespace std;
#define maxn 200050
int n, m;
int a[maxn];
int pos[1000050];
int maxx = 0;
int jl[maxn >> 1];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
		a[i] += a[i - 1];
		for (int j = a[i - 1]; j<a[i]; j++)
			pos[j] = i - 1;
		pos[a[i]] = i;
	}
 
	//     for(int i=1;i<=a[n];i++)
	//      cout<<pos[i]<<" ";
 
	scanf("%d", &m);
	int x;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		if (x<maxx)printf("Impossible\n");
		else
		{
			if (jl[x])printf("%d\n", jl[x]);
			else
			{
				int poss = 0; int numm = x;
 
 
				while (numm < a[n])
				{
					poss = pos[numm];
					numm = x + a[poss];
					jl[x]++;
				}
				jl[x]++;
                printf("%d\n", jl[x]);
			}
		}
	}
	return 0;
}
