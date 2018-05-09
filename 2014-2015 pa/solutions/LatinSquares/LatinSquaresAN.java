import java.util.*;

public class LatinSquaresAN {
    public static long toLong(char c) {
        return 1L << Character.digit(c, 36);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        long mask = (1L << n) - 1;
        long[][] arr = new long[n][n];
        for (int i = 0; i < n; i++) {
            String line = s.next();
            for (int j = 0; j < n; j++) arr[i][j] = toLong(line.charAt(j));
        }

        boolean isReduced = true;
        for (int i = 1; i < n; i++) {
            if (arr[0][i] < arr[0][i-1]) isReduced = false;
            if (arr[i][0] < arr[i-1][0]) isReduced = false;
        }

        boolean isLatin = true;
        for (int i = 0; i < n; i++) {
            long row = 0, col = 0;
            for (int j = 0; j < n; j++) {
                row += arr[i][j];
                col += arr[j][i];
            }
            if (row != mask || col != mask) isLatin = false;
        }

        if (isLatin && isReduced) {
            System.out.println("Reduced");
        } else if (isLatin) {
            System.out.println("Not Reduced");
        } else {
            System.out.println("No");
        }
    }
}
