#include <iostream>
#include <cmath>

const int maxn=1e6+7;

int minDiv[maxn],phi[maxn],sum[maxn];
LL n, ans[maxn];

void genPhi()
{
	for(int i=1;i<maxn;i++)
	{
		minDiv[i]=i;
	}
	for(int i=2;i*i<maxn;i++)
	{
		if(minDiv[i]==i)
		{
			for(int j=i*i;j<maxn;j+=i)
			{
				minDiv[j]=i;
			}
		}
	}
	phi[1]=1;
	for(int i=2;i<maxn;++i)
	{
		phi[i]=phi[i/minDiv[i]];
		if((i/minDiv[i])%minDiv[i]==0)
		{
			phi[i]*=minDiv[i];
		}
		else
		{
			phi[i]*=minDiv[i]-1;
		}
	}
}

int main(int argc, char *argv[]) { 
	genPhi(); 
	
	
}