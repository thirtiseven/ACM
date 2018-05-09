import java.io.*;
import java.util.*;

public class delayedwork_xiaowuc1_linear {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		int lhs = 1;
		double ret = cost(1);
		for(int i = 2; true; i++) {
			double curr = cost(i);
			if(curr < ret){
				ret = curr;
			}
			else {
				break;
			}
		}
		System.out.printf("%.3f\n", ret);
	}
	static int k, p, x;

	public static double cost(int m) {
		return x*1.0*m + (k*1.0/m)*p;
	}

}
