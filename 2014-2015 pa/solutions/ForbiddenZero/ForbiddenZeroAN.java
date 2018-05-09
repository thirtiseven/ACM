import java.util.*;

public class ForbiddenZeroAN {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        n++;
        System.out.println(Integer.toString(n).replace('0', '1'));
    }
}
