import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int CC = 1; CC <= T; CC++) {
			int n;
			ArrayList<BigDecimal> a = new ArrayList<BigDecimal>();
			n = in.nextInt();
			for (int i = 0; i < n; i++) {
				String str = in.next();
				String[] st = str.split(":");
				BigDecimal x = new BigDecimal(st[0]);
				BigDecimal y = new BigDecimal(st[1]);
				y = y.add(x);
				x = x.divide(y, 100, BigDecimal.ROUND_HALF_EVEN);
				a.add(x);
			}
			Collections.sort(a);
			BigDecimal aa = new BigDecimal(1.0);
			BigDecimal now = new BigDecimal(0);
			int ans = 0;
			for (int i = 0; i < n; i++) {
				now = now.add(a.get(i));
				if (now.compareTo(aa) < 0) {
					ans++;
				}
			}
			System.out.println("Case #" + CC + ": " + ans);
		}
	}
}