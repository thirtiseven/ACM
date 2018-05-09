import java.util.*;
import java.text.DecimalFormat;

/*
This is considerably less elegant and stable than the C++ solution, but
we want it to pass.
*/
public class StraightShotAN {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int X = s.nextInt();
        double v = s.nextDouble();
        int[] width = new int[N];
        double[] speed = new double[N];
        for (int i = 0; i < N; i++) {
            width[i] = -s.nextInt() + s.nextInt();
            speed[i] = s.nextDouble();
        }

        double lower = -Math.PI / 3 - 2e-10;
        double upper = Math.PI / 3 + 2e-10;
        while (upper - lower > 1e-10) {
            double mid = (lower + upper) / 2;
            double xv = v * Math.cos(mid);
            double yv = v * Math.sin(mid);
            double shift = yv * (X / xv);
            for (int i = 0; i < N; i++) {
                shift += speed[i] * width[i] / xv;
            }
            if (shift > 0) upper = mid;
            else lower = mid;
        }
        double ans = X / (v * Math.cos(lower));
        if (ans > 2 * X / v) {
            System.out.println("Too hard");
        } else {
            System.out.println(new DecimalFormat("0.000").format(ans));
        }
    }
}