#include <iostream>
#include <vector>
#include <string>
using namespace std ;
typedef long long ll ;
int main() {
   int N, M ;
   cin >> N >> M ;
   string s ;
   vector<ll> res(M+1) ;
   for (int i=0; i<=M; i++)
      res[i] = 1 ;
   for (int i=0; i<N; i++) {
      vector<ll> nr(M+1) ;
      cin >> s ;
      int hib = -1 ;
      int lor = M ;
      for (int j=0; j<M; j++)
         if (s[j] == 'R') {
            lor = min(j, lor) ;
         } else if (s[j] == 'B') {
            hib = j ;
         }
      ll s = 0 ;
      for (int j=M; j>=0; j--) {
         if (j > hib && j <= lor)
            s += res[j] ;
         if (j <= lor)
            nr[j] += s ;
      }
      swap(nr, res) ;
   }
   cout << res[0] << endl ;
}
