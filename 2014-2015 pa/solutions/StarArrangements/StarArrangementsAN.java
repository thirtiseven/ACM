import java.util.*;

public class StarArrangementsAN {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.println("" + n + ":") ;
        for (int i = 2; i < n; i++) {
            if (n % (2 * i - 1) == 0 || (n - i) % (2 * i - 1) == 0) {
                System.out.println(i + "," + (i - 1));
            }
            if (n % i == 0) {
                System.out.println(i + "," + i);
            }
        }
    }
}
