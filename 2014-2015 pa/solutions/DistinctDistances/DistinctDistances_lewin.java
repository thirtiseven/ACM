import java.util.HashSet;
import java.util.Scanner;

/**
 * Created by Lewin on 10/17/2017.
 */
public class DistinctDistances_lewin {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n <= 2) {
            System.out.println(1);
            return;
        }
        int[] x = new int[n], y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt() * 2;
            y[i] = in.nextInt() * 2;
        }
        int best = n;
        for (int a1 = 0; a1 < n; a1++) {
            for (int a2 = a1+1; a2 < n; a2++) {
                for (int b1 = a1; b1 < n; b1++) {
                    for (int b2 = b1+1; b2 < n; b2++) {
                        if (a1 == b1 && a2 == b2) continue;
                        int ax = (x[a1] + x[a2]) / 2, ay = (y[a1] + y[a2]) / 2;
                        int bx = (x[b1] + x[b2]) / 2, by = (y[b1] + y[b2]) / 2;

                        int dax = y[a1] - y[a2], day = x[a2] - x[a1];
                        int dbx = y[b1] - y[b2], dby = x[b2] - x[b1];
                        long[] l1 = getLine(ax, ay, dax, day);
                        long[] l2 = getLine(bx, by, dbx, dby);
                        long cx,cy,cd;
                        if (dax * dby == dbx * day) {
                            cx = ax; cy = ay; cd = 1;
                        } else {
                            long[] c = getIntersection(l1,l2);
                            cx = c[0]; cy = c[1]; cd = c[2];
                        }

                        HashSet<Long> hs = new HashSet<>();
                        for (int j = 0; j < n; j++) {
                            hs.add((cx - x[j] * cd) * (cx - x[j] * cd) + (cy - y[j] * cd) * (cy - y[j] * cd));
                        }
                        best = Math.min(best, hs.size());
                    }
                }
            }
        }
        System.out.println(best);
    }

    public static long[] getLine(int ox, int oy, int vx, int vy) {
        return new long[]{vy, -vx, ox*vy-oy*vx};
    }

    public static long[] getIntersection(long[] l1, long[] l2) {
        long x = l2[1] * l1[2] - l1[1] * l2[2];
        long d = l2[1] * l1[0] - l1[1] * l2[0];
        long y;
        if (l1[1] != 0) {
            y = (-l1[0] * x + l1[2] * d);
            x *= l1[1];
            d *= l1[1];
        } else {
            y = (-l2[0] * x + l2[2] * d);
            x *= l2[1];
            d *= l2[1];
        }
        return new long[]{x,y,d};
    }
}
