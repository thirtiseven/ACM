#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
typedef long long ll ;
vector<pair<ll, ll> > pts ;
ll n, r ;
vector<ll> dists ;
void check(ll x, ll y, ll denom) {
   dists.clear() ;
   for (int i=0; i<n; i++) {
      ll dx = x - denom * pts[i].first ;
      ll dy = y - denom * pts[i].second ;
      if (abs(dx) > (1LL<<31) || abs(dy) > (1LL<<31))
         cout << "Potential for overflow" << endl ;
      dists.push_back(dx*dx+dy*dy) ;
   }
   sort(dists.begin(), dists.end()) ;
   ll t = unique(dists.begin(), dists.end()) - dists.begin() ;
   r = min(t, r) ;
}
int main() {
   cin >> n ;
   for (int i=0; i<n; i++) {
      ll x, y ;
      cin >> x >> y ;
      pts.push_back(make_pair(2*x, 2*y)) ;
   }
   r = n - 1 ;
   if (r == 0)
      r = 1 ;
   for (int a=0; a<pts.size(); a++)
      for (int b=a+1; b<pts.size(); b++) {
         check(pts[a].first+pts[b].first, pts[a].second+pts[b].second, 2) ;
         for (int c=a+1; c<pts.size(); c++)
            for (int d=c+1; d<pts.size(); d++) {
               ll dx1 = pts[b].first - pts[a].first ;
               ll dy1 = pts[b].second - pts[a].second ;
               ll dx2 = pts[d].first - pts[c].first ;
               ll dy2 = pts[d].second - pts[c].second ;
               ll c1 = (dx1 * (pts[b].first + pts[a].first) + dy1 * (pts[b].second + pts[a].second)) >> 1 ;
               ll c2 = (dx2 * (pts[d].first + pts[c].first) + dy2 * (pts[d].second + pts[c].second)) >> 1 ;
               ll xx = c1 * dy2 - c2 * dy1 ;
               ll yy = dx1 * c2 - dx2 * c1 ;
               ll denom = dx1 * dy2 - dx2 * dy1 ;
               if (denom == 0) // Parallel Lines, Blondie, 1978
                  continue ;
               check(xx, yy, denom) ;
            }
      }
   cout << r << endl ;
}
