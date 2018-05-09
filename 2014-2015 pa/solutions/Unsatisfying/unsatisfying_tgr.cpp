#include <iostream>
#include <vector>
using namespace std ;
/*
 *   Convert input form into zero-based node number.  Node number 0
 *   is for v1; node number 1 is for ~v1; then v2, ~v2, v3, ~v3, etc.
 */
int normalize(int v) {
   if (v < 0)
      return -2 * v - 1 ;
   else
      return 2*(v-1) ;
}
vector<int> L ;
vector<char> visited ;
vector<vector<int > > edges ;
void visit(int v) {
   if (visited[v])
      return ;
   visited[v] = 1 ;
   for (int i=0; i<edges[v].size(); i++)
      visit(edges[v][i]) ;
   L.push_back(v) ;
}
vector<int> roots ;
void assign(int v, int root) {
   if (roots[v] >= 0)
      return ;
   roots[v] = root ;
   // we exploit the structure of the graph to calculate inneighbors
   // from outneighbors; if pa -> pb then ~pb -> ~pa.
   for (int i=0; i<edges[v^1].size(); i++)
      assign(edges[v^1][i]^1, root) ;
}
vector<int> visitcookie ;
int cookie = 1 ;
vector<vector<char> > reachable ;
vector<char> frompos ;
vector<char> reachesneg ;
void dfs(int root, int v) {
   if (visitcookie[v] == cookie)
      return ;
   visitcookie[v] = cookie ;
   reachable[root][v] = 1 ;
   reachesneg[root] |= reachesneg[v] ;
   frompos[v] |= frompos[root] ;
   for (int i=0; i<edges[v].size(); i++)
      dfs(root, edges[v][i]) ;
}
int main() {
   int n, m, a, b ;
   cin >> n >> m ;
   edges.resize(2*n) ;
   for (int i=0; i<m; i++) {
      cin >> a >> b ;
      a = normalize(a) ;
      b = normalize(b) ;
      // a or b means ~a -> b and also ~b -> a
      edges[a ^ 1].push_back(b) ;
      edges[b ^ 1].push_back(a) ;
   }
   // do SCC analysis using Kosaraju's algorithm.
   visited.resize(2*n) ;
   for (int i=0; i<2*n; i++)
      visit(i) ;
   roots.resize(2*n) ;
   for (int i=0; i<2*n; i++)
      roots[i] = -1 ;
   for (int i=L.size()-1; i>=0; i--)
      assign(L[i], L[i]) ;
   // check for 0 return
   for (int i=0; i<2*n; i += 2)
      if (roots[i] == roots[i^1]) {
         cout << 0 << endl ;
         return 0 ;
      }
   // mark which scc's have *some* negative literal and which have *some*
   // positive literal.
   reachesneg.resize(2*n) ;
   frompos.resize(2*n) ;
   for (int i=1; i<2*n; i += 2)
      reachesneg[roots[i]] = 1 ;
   for (int i=0; i<2*n; i += 2)
      frompos[roots[i]] = 1 ;
   // check for 1 return; some SCC with A has path to some SCC with A'.
   // For each scc, do DFS and mark nodes visited.  This makes it
   // quadratic in nodes.  Along the way we mark which scc's are reachable from
   // which other scc's.
   reachable.resize(2*n) ;
   for (int i=0; i<2*n; i++)
      reachable[i].resize(2*n) ;
   visitcookie.resize(2*n) ;
   for (int i=0; i<2*n; i++) {
      if (roots[i] != i)
         continue ;
      cookie++ ;
      dfs(i, i) ;
      for (int j=0; j<2*n; j += 2)
         if (roots[j] == i && visitcookie[j^1] == cookie) {
            cout << 1 << endl ;
            return 0 ;
         }
   }
   // check for a return of 2, based on some literal where the
   // positive reaches some negative, and the negative is reachable
   // from some positive.
   for (int i=0; i<2*n; i += 2)
      if (reachesneg[roots[i]] && frompos[roots[i^1]]) {
         cout << 2 << endl ;
         return 0 ;
      }
   // no solution.
   cout << -1 << endl ;
}
