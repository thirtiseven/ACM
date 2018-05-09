#include <iostream>
#include <map>
#include <vector>
using namespace std ;
typedef long long ll ;
vector<ll> cache ;
vector<int> p ;
ll n, X, mm, calls ;
ll recur(int togo, ll seen, ll X, int omit, int prev, int tobeat) {
   calls++ ;
   if (togo == 0)
      return 1 ;
   if (X < 0)
      return 0 ;
   ll key = seen + ((X * mm + prev + 1) << n) ;
   if (cache[key] >= 0)
      return cache[key] ;
   ll r = 0 ;
   for (int i=0; i<n; i++) {
      if (i == omit || ((seen >> i) & 1))
         continue ;
      int cost = 0 ;
      if (prev >= 0 && p[i] < p[prev])
         cost = 1 ;
      if (cost + p[i] <= tobeat)
         cost = tobeat - p[i] + 1 ;
      if (cost * togo > X)
         continue ;
      r += recur(togo-1, seen | (1LL<<i), X-cost*togo, -1, i, p[i]) ;
   }
   cache[key] = r ;
   return r ;
}
int main(int argc, char *[]) {
   cin >> n >> X ;
   p.resize(n) ;
   for (int i=0; i<n; i++)
      cin >> p[i] ;
   int hi = 0 ;
   mm = n + 1 ;
   ll cachesize = (1LL<<n) * mm * (X + 1) ;
   cache.resize(cachesize) ;
   for (int i=0; i<cachesize; i++)
      cache[i] = -1 ;
   for (int i=1; i<n; i++)
      if (p[i] > p[hi])
         hi = i ;
   ll r = recur(n, 0, X, hi, -1, p[hi]) ;
   if (argc > 1)
      cout << r << " " << calls << endl ;
   else 
      cout << r << endl ;
}
