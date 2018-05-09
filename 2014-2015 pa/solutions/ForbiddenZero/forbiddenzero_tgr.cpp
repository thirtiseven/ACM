#include <iostream>
using namespace std ;
int main() {
   int n ;
   cin >> n ;
   int inc = 1 ;
   while (n % (10 * inc) == (10 * inc) - 1)
      inc *= 10 ;
   n += 1 + inc / 9 ;
   cout << n << endl ;
}
