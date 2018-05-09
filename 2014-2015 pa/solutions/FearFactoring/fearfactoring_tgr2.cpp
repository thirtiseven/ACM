#include <iostream>
#include <cmath>
using namespace std ;
typedef long long ll ;
ll triangle(ll a, ll b) {
   return (a + b + 1) * (b - a) / 2 ;
}
ll factorsum(ll a, ll b) {
   ll hif = sqrt(b) ;
   ll r = 0 ;
   for (ll f=1; f<=hif; f++)
      r += f * (b/f - a/f) + triangle(max(hif, a/f), max(hif, b/f)) ;
   return r ;
}
int main() {
   ll a, b ;
   cin >> a >> b ;
   ll s = factorsum(a-1, b) ;
   cout << s << endl ;
}
