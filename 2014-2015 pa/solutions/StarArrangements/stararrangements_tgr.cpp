#include <iostream>
using namespace std ;
int main() {
   int n ;
   while (cin >> n) {
      cout << n << ":" << endl ;
      for (int toprow=2; toprow<n; toprow++)
         for (int nextrow=toprow-1; nextrow<=toprow; nextrow++) {
            int mod = n % (toprow + nextrow) ;
            if (mod == 0 || mod == toprow)
               cout << toprow << "," << nextrow << endl ;
         }
   }
}
