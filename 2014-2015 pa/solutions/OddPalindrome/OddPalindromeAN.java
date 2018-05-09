import java.util.*;

public class OddPalindromeAN {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        char[] str = s.next().toCharArray();
        for (int i = 0; i < str.length - 1; i++) {
            if (str[i] == str[i + 1]) {
                System.out.println("Or not.");
                return;
            }
        }
        System.out.println("Odd.");
    }
}
