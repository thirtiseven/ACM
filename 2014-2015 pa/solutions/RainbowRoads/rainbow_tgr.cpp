/*
 *   Rainbow roads linear-time solution.
 */
#include <iostream>
using namespace std ;
const int MAXN = 100001 ;
struct edge {
   edge() : src(0), dst(0), state(0), color(0), next(0) {}
   edge(int src_, int dst_, int color_, edge *next_)
             : src(src_), dst(dst_), color(color_), state(0), next(next_) {} 
   int src, dst ;
   int color ;
   int state ; // good, marked, chased
   edge *next ;
} *heads[MAXN], edges[2*MAXN] ;
int edgealloc = 0 ;
int colorcount[MAXN] ;
int edgecount[MAXN] ;
char badnode[MAXN] ;
int n ;
void addedge(int src_, int dst_, int c_) {
   edge *e = edges + edgealloc++ ;
   *e = edge(src_, dst_, c_, heads[src_]) ;
   heads[src_] = e ;
   edgecount[src_]++ ;
}
edge *q[2*MAXN] ;
int main() {
   cin >> n ;
   for (int i=1; i<n; i++) {
      int a, b, c ;
// using scanf is much faster than using cin here
//    scanf("%d %d %d", &a, &b, &c) ;
      cin >> a >> b >> c ;
      addedge(a, b, c) ;
      addedge(b, a, c) ;
   }
   int goodnodes = n ;
   // mark edges that are bad
   for (int src=0; src<n; src++)
      if (edgecount[src] > 2) {
         for (edge *e = heads[src]; e; e=e->next)
            colorcount[e->color]++ ;
         for (edge *e = heads[src]; e; e=e->next)
            if (colorcount[e->color] > 1)
               e->state = 1 ;
         for (edge *e = heads[src]; e; e=e->next)
            colorcount[e->color] = 0 ;
      } else if (edgecount[src] == 2 && 
                 heads[src]->color == heads[src]->next->color) {
         heads[src]->state = 1 ;
         heads[src]->next->state = 1 ;
      }
   int qput = 0 ;
   int qget = 0 ;
   for (int i=0; i<2*n; i++)
      if (edges[i].state)
         q[qput++] = &edges[i] ;
   while (qget < qput) {
      edge *e = q[qget++] ;
      if (badnode[e->dst] < 2) {
         if (badnode[e->dst] == 0)
            goodnodes-- ;
         badnode[e->dst]++ ;
         for (edge *e2 = heads[e->dst]; e2; e2=e2->next)
            if (e2->state == 0 && e2->dst != e->src) {
               q[qput++] = e2 ;
               e2->state = 1 ;
            }
      }
   }
   cout << goodnodes << endl ;
   for (int i=1; i<=n; i++)
      if (!badnode[i])
         cout << i << endl ;
}
