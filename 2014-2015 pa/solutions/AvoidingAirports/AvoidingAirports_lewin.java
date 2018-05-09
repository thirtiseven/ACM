import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * Created by lewin on 10/17/17.
 */
public class AvoidingAirports_lewin {
    static class ConvexHullOptimization {
        public ArrayList<Long> A, B;
        public int len, ptr;

        public ConvexHullOptimization() {
            A = new ArrayList<>(); B = new ArrayList<>();
            len = 0; ptr = 0;
        }

        // a descends
        public void addLine(long a, long b) {
            // intersection of (A[len-2],B[len-2]) with (A[len-1],B[len-1]) must lie to the left of intersection of (A[len-1],B[len-1]) with (a,b)
            while (len >= 2 && (B.get(len - 2) - B.get(len - 1)) * (a - A.get(len - 1)) >= (B.get(len - 1) - b) * (A.get(len - 1) - A.get(len - 2))) {
                --len;
            }
            if (len == A.size()) {
                A.add(a);
                B.add(b);
            } else {
                A.set(len, a);
                B.set(len, b);
            }
            len++;
            ptr = Math.min(ptr, len-1);
        }


        public long minValue(long x) {
            ptr = Math.min(ptr, len - 1);
            while (ptr + 1 < len && A.get(ptr + 1) * x + B.get(ptr + 1) <= A.get(ptr) * x + B.get(ptr)) {
                ++ptr;
            }
            return A.get(ptr) * x + B.get(ptr);
        }
    }

    static class Edge {
        public int from, to, start, end;

        public Edge(int from, int to, int start, int end) {
            this.from = from;
            this.to = to;
            this.start = start;
            this.end = end;
        }
    }

    static class Event {
        public int idx, time, type;
        public Event(int idx, int time, int type) {
            this.idx = idx;
            this.time = time;
            this.type = type;
        }
    }

    public static void main (String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        Edge[] es = new Edge[m];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            es[i] = new Edge(
                    Integer.parseInt(st.nextToken())-1,
                    Integer.parseInt(st.nextToken())-1,
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())
            );
        }
        Event[] ees = new Event[2*m];
        for (int i = 0; i < m; i++) {
            ees[i] = new Event(i, es[i].start, +1);
            ees[i+m] = new Event(i, es[i].end, -1);
        }
        Arrays.sort(ees, Comparator.comparingInt(x -> x.time));
        ConvexHullOptimization[] cs = new ConvexHullOptimization[n];
        for (int i = 0; i < n; i++) cs[i] = new ConvexHullOptimization();
        cs[0].addLine(0, 0);

        boolean[] reached = new boolean[n];
        reached[0] = true;
        long[] costedge = new long[m];
        Arrays.fill(costedge, Long.MAX_VALUE);
        for (Event e : ees) {
            int idx = e.idx, time = e.time, type = e.type;
            int src = es[idx].from, dst = es[idx].to;

            if (type == +1) {
                if (reached[src]) {
                    costedge[idx] = 1L * time * time + cs[src].minValue(time);
                }
            } else {
                if (costedge[idx] != Long.MAX_VALUE) {
                    cs[dst].addLine(-2 * time, costedge[idx] + 1L * time * time);
                    reached[dst] = true;
                }
            }
        }
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            if (es[i].to == n-1) ans = Math.min(ans, costedge[i]);
        }

        System.out.println(ans);
        System.exit(0);
    }
}
