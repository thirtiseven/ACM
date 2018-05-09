import java.io.* ;
import java.util.* ;
class Edge {
   Edge(int dest_, long lowid_, long highid_) {
      dest = dest_ ;
      lowid = lowid_ ;
      highid = highid_ ;
   }
   boolean goodfor(long id) {
      return id >= lowid && id <= highid ;
   }
   int dest ;
   long lowid, highid ;
}
public class securitybadge_tgr {
   static long[] visited ;
   static long cookie = 100 ;
   static ArrayList<ArrayList<Edge>> edges ;
   static boolean visit(int node, long id, int dst) {
      if (node == dst)
         return true ;
      if (visited[node] == cookie)
         return false ;
      visited[node] = cookie ;
      for (Edge e : edges.get(node))
         if (e.goodfor(id) && visit(e.dest, id, dst))
            return true ;
      return false ;
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      int N = sc.nextInt() ;
      int M = sc.nextInt() ;
      long MAXID = sc.nextLong() ;
      int src = sc.nextInt()-1 ;
      int dst = sc.nextInt()-1 ;
      visited = new long[N] ;
      edges = new ArrayList<ArrayList<Edge>>() ;
      for (long i=0; i<N; i++)
         edges.add(new ArrayList<Edge>()) ;
      ArrayList<Long> mentioned = new ArrayList<Long>() ;
      for (long i=0; i<M; i++) {
         int from = sc.nextInt()-1 ;
         int to = sc.nextInt()-1 ;
         long lowid = sc.nextLong()-1 ;
         long highid = sc.nextLong()-1 ;
         mentioned.add(lowid) ;
         mentioned.add(highid+1) ;
         edges.get(from).add(new Edge(to, lowid, highid)) ;
      }
      Collections.sort(mentioned) ;
      long r = 0 ;
      for (int i=0; i+1<mentioned.size(); i++) {
         if (mentioned.get(i).equals(mentioned.get(i+1)))
            continue ;
         cookie++ ;
         if (visit(src, mentioned.get(i), dst))
            r += mentioned.get(i+1)-mentioned.get(i) ;
      }
      System.out.println(r) ;
   }
}
