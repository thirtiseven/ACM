import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * Created by lewin on 10/17/17.
 */
public class AvoidingAirports_lewin_optimized {
    public static int[] len, ptr, base;
    public static long[] A, B;
    static void addLine(int idx, long a, long b) {
        int l;
        while ((l = len[idx]) >= 2 + base[idx] && (B[l-2] - B[l-1]) * (a - A[l-1]) >= (B[l-1] - b) * (A[l-1] - A[l-2])) {
            --len[idx];
        }
        A[l] = a; B[l] = b;
        ptr[idx] = Math.min(ptr[idx], len[idx]++);
    }

    static long minValue(int idx, long x) {
        int p;
        while ((p = ptr[idx]) + 1 < len[idx] && A[p+1] * x + B[p+1] <= A[p] * x + B[p]) {
            ++ptr[idx];
        }
        return A[p] * x + B[p];
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
        InputReader in = new InputReader(System.in);
        int n = in.nextInt(), m = in.nextInt();
        int[] indeg = new int[n];
        Event[] ees = new Event[2*m];
        int[] f = new int[m], t = new int[m];
        int[] idd = new int[1000010];
        Arrays.fill(idd, -1);
        for (int i = 0; i < m; i++) {
            int from = in.nextInt()-1, to = in.nextInt()-1, start = in.nextInt(), end = in.nextInt();
            ees[2*i+0] = new Event(i, start, +1);
            ees[2*i+1] = new Event(i, end, -1);
            idd[start] = 2*i+0;
            idd[end] = 2*i+1;
            indeg[to]++;
            f[i] = from;
            t[i] = to;
        }

        base = new int[n];
        indeg[0]++;
        for (int i = 1; i < n; i++) {
            base[i] = base[i-1] + indeg[i-1];
        }

        len = new int[n];
        ptr = new int[n];
        System.arraycopy(base, 0, ptr, 0, n);
        System.arraycopy(base, 0, len, 0, n);
        A = new long[m+1];
        B = new long[m+1];
        addLine(0, 0, 0);
        boolean[] reached = new boolean[n];
        reached[0] = true;
        long[] costedge = new long[m];
        Arrays.fill(costedge, Long.MAX_VALUE);
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < idd.length; i++) {
            if (idd[i] == -1) continue;
            Event e = ees[idd[i]];
            int idx = e.idx;

            if (e.type == +1) {
                if (reached[f[idx]]) {
                    costedge[idx] = 1L * i * i + minValue(f[idx], i);
                }
            } else {
                if (costedge[idx] != Long.MAX_VALUE) {
                    if (t[idx] == n-1) ans = Math.min(ans, costedge[idx]);
                    addLine(t[idx], -2 * i, costedge[idx] + 1L * i * i);
                    reached[t[idx]] = true;
                }
            }
        }
        System.out.println(ans);
        System.exit(0);
    }

    static  class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }


        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isEndOfLine(int c) {
            return c == '\n' || c == -1;
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }
    }
}
