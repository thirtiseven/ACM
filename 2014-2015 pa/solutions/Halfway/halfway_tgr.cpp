#include <iostream>
#include <cmath>
using namespace std ;
typedef long long ll ;
int main() {
   ll n ;
   cin >> n ;
   ll totwork = n * (n-1) / 2 ;
   ll m = (1-sqrt(0.5)) * n - 2 ;
   if (m < 0)
      m = 0 ;
   while (m * (m-1) <= totwork)
      m++ ;
   cout << (n+1-m) << endl ;
}
