#include<iostream>
using namespace std;


int main()
{
	long long a, b;
	cin >> a;
	if (a > 4)
	{for(b=1;b<a/2;b++)
	{if((2*(b+1)*(2*a-b))>(a*a+a))
	{
		cout << b; break;
	}
	}
    }
	else
	{
		cout << 1;
	}
    return 0;
}