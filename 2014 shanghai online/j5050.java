import java.math.*;
import java.util.Scanner;

public class Main {
	public static  BigInteger gcd (BigInteger a, BigInteger b) {
		BigInteger t = BigInteger.ZERO;
		while (b.equals(BigInteger.ZERO) == false) {
			t = a.mod(b);
			a = b;
			b = t;
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T;
		BigInteger l, w, ans;
		T = input.nextInt();
		for (int CC = 1; CC <= T; CC++) {
			l = input.nextBigInteger(2);
			w = input.nextBigInteger(2);
			ans = gcd(l, w);
			System.out.println("Case #" + CC + ": " + gcd(l, w).toString(2));
		}
	}
}