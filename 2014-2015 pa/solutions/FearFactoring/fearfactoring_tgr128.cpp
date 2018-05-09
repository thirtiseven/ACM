#include <iostream>
#include <cmath>
using namespace std ;
typedef __int128 ll ;
ll factorsum(ll p) {
   ll hif = sqrt(p) ;
   ll below = hif * (hif + 1) / 2 ;
   ll r = p + p * (p + 1) / 2 - below ;
   for (ll f=2; f*f<=p; f++) {
      r += f * (p/f) ;
      if (f*f != p) {
         ll cnt = p/f ;
         r += cnt * (cnt + 1) / 2 - below ;
      }
   }
   return r ;
}
int main() {
   long long a, b ;
   cin >> a >> b ;
   ll s = factorsum(b) - factorsum(a-1) ;
   cout << (long long)s << endl ;
}
