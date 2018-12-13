#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {  
	int a,b,c;
	int aa,bb,cc;
	cin>>a>>b>>c;
	cin>>aa>>bb>>cc;
	int sum=0;
	
	sum+=max(aa-a,0)+max(bb-b,0)+max(cc-c,0);
	cout<<sum<<endl;
	
}