#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{int n,i,j;
 char a[100];
 cin>>a;
 n=strlen(a);
 for(i=0;i<n;i++)
 {for(j=i+1;j<n;j++)
 {if((a[i]==a[j])&&((j-i)%2==1))
 {while(j>i)
 {if(a[i]!=a[j])
	break;
	i++;
	j--;
 }
 if(i>j)
 {cout<<"Or not.";return 0;}
 }
 }
 }
 cout<<"Odd.";
	return 0;
}