import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Lewin on 10/17/2017.
 */
public class EnlargingEnthusiasm_lewin {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), X = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) p[i] = in.nextInt();
        Arrays.sort(p);

        long[][][] nways = new long[1 << n][n][X + 1];
        for (int mask = 0; mask < 1 << n; mask++) {
            int have = Integer.bitCount(mask);
            if (have == 1) {
                int who = Integer.numberOfTrailingZeros(mask);
                if (who == n-1) continue;
                int need = (p[n - 1] + 1 - p[who]) * n;
                if (need <= X) {
                    nways[mask][who][need] = 1;
                }
                continue;
            }
            for (int who = 0; who < n; who++) {
                if (((mask >> who) & 1) == 0) continue;
                for (int prev = 0; prev < n; prev++) {
                    if (prev != who && (((mask >> prev) & 1) == 1)) {
                        int need = Math.max(0, p[prev] + 1 - p[who]) * (n - have + 1);
                        for (int pneed = 0; pneed + need <= X; pneed++) {
                            nways[mask][who][pneed+need] += nways[mask^(1<<who)][prev][pneed];
                        }
                    }
                }
            }
        }

        long tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= X; j++) {
                tot += nways[(1<<n)-1][i][j];
            }
        }
        System.out.println(tot);
    }
}
