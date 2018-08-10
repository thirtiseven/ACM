import java.math.*;
import java.util.Scanner;

public class j5047 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T;
		BigInteger n, ans;
		BigInteger eight = new BigInteger("8");
		BigInteger seven = new BigInteger("7");
		T = input.nextInt();
		for (int CC = 1; CC <= T; CC++) {
			n = input.nextBigInteger();
			ans = n.multiply(n);
			ans = eight.multiply(ans);
			ans = ans.subtract(seven.multiply(n));
			ans = ans.add(BigInteger.ONE);
			System.out.println("Case #" + CC + ": " + ans);
		}

	}
}