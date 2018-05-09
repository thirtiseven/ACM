#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std ;
int main() {
   int n ;
   cin >> n ;
   vector<string> b(n) ;
   for (int i=0; i<n; i++)
      cin >> b[i] ;
   string base = b[0] ;
   sort(base.begin(), base.end()) ;
   int islatin = 1 ;
   int isreduced = 1 ;
   if (b[0] != base)
      isreduced = 0 ;
   for (int i=0; i<n; i++) {
      string work = b[i] ;
      sort(work.begin(), work.end()) ;
      if (work != base)
         islatin = 0 ;
      for (int j=0; j<n; j++)
         work[j] = b[j][i] ;
      if (i == 0 && work != base)
         isreduced = 0 ;
      sort(work.begin(), work.end()) ;
      if (work != base)
         islatin = 0 ;
   }
   if (islatin && isreduced)
      cout << "Reduced" << endl ;
   else if (islatin)
      cout << "Not Reduced" << endl ;
   else
      cout << "No" << endl ;
}
