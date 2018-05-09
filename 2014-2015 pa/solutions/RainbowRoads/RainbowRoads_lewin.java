import java.util.*;

/**
 * Created by lewin on 10/10/17.
 */
public class RainbowRoads_lewin {
    static class Edge {
        public int to,col;
        public Edge(int to, int col) {
            this.to = to;
            this.col = col;
        }
    }

    public static List<Edge>[] graph;
    public static HashMap<Integer, Integer>[] colcount;
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        graph = new List[n];
        colcount = new HashMap[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            colcount[i] = new HashMap<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a = in.nextInt(), b = in.nextInt(), r = in.nextInt();
			--a; // Convert from 1-based input to zero-based internal indices
			--b;
			--r;
            graph[a].add(new Edge(b,r));
            graph[b].add(new Edge(a,r));
            colcount[a].merge(r, 1, Integer::sum);
            colcount[b].merge(r, 1, Integer::sum);
        }
        ans = new ArrayList<>();
        tc = new int[n];
        dfs(0, -1, -1);

        for (int i = 0; i < n; i++) {
            if (gsum == -tc[i]) {
                ans.add(i);
            }
        }
        System.out.println(ans.size());
        for (int x : ans) {
            System.out.println(x+1);
        }
        System.exit(0);
    }
    public static ArrayList<Integer> ans;
    public static int gsum, csum;
    public static int[] tc;
    public static void dfs(int node, int par, int pcolor) {
        if (colcount[node].getOrDefault(pcolor, 0) > 1) {
            gsum++;
            csum--;
        }
        tc[node] = csum;
        for (Edge next : graph[node]) {
            if (next.to == par) continue;
            if (colcount[node].getOrDefault(next.col, 0) > 1) {
                csum++;
            }
            dfs(next.to, node, next.col);
            if (colcount[node].getOrDefault(next.col, 0) > 1) {
                csum--;
            }
        }
        if (colcount[node].getOrDefault(pcolor, 0) > 1) {
            csum++;
        }
    }
}
