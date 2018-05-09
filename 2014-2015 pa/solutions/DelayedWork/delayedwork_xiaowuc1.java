import java.io.*;
import java.util.*;

public class delayedwork_xiaowuc1 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		int lhs = 1;
		int rhs = 1000000000;
		while(rhs - lhs > 5) {
			int mid = (lhs+rhs)/2;
			if(cost(mid) < cost(mid+1)) {
				rhs = mid+1;
			}
			else {
				lhs = mid;
			}
		}
//System.out.println(lhs + " " + rhs);
		double ret = Double.MAX_VALUE;
		for(int i = lhs; i <= rhs; i++) {
			ret = Math.min(ret, cost(i));
		}
		System.out.printf("%.3f\n", ret);
	}
	static int k, p, x;

	public static double cost(int m) {
		return x*1.0*m + (k*1.0/m)*p;
	}

}
