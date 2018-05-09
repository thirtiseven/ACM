#include <iostream>
#include <map>
#include <string>
using namespace std ;
typedef long long ll ;
string s ;
const int INFTY = 1000000 ;
ll m ;
map<ll, ll> cache ;
int recur(int left, int right, int cin, int cout) {
   ll key = left + m * (right + m * (cin + 2 * cout)) ;
   if (cache.find(key) != cache.end())
      return cache[key] ;
   int r = INFTY ;
   if (left == right) {
      int dig = s[left] - '0' + cin ;
      if (dig == 10 && cout == 0)
         r = INFTY ;
      else if (cout == 1)
         r = 10 - dig ;
      else
         r = 0 ;
   } else if (left > right) {
      if ((cin == 0 && cout != 1) || (cin == 1 && cout != 0))
         r = 0 ;
   } else {
      int ldig = s[left] - '0' ;
      int rdig = s[right] - '0' + cin ;
      for (int linc=0; linc<=10; linc++)
         for (int rinc=0; rinc<10; rinc++)
            if ((ldig + linc) % 10 == (rdig + rinc) % 10 &&
                ((cout != 0 && (ldig + linc >= 10)) ||
                 (cout != 1 && (ldig + linc < 10)))) {
               if (linc < 10)
                  r = min(r, linc+rinc+
                recur(left+1, right-1, (rdig+rinc > 9 ? 1 : 0), 0)) ;
               if (linc > 0)
                  r = min(r, linc-1+rinc+
                recur(left+1, right-1, (rdig+rinc > 9 ? 1 : 0), 1)) ;
            }
   }
   cache[key] = r ;
   return r ;
}
int main() {
   cin >> s ;
   m = s.size() + 2 ;
   int r = recur(0, s.size()-1, 0, 2) ;
   cout << r << endl ;
}
