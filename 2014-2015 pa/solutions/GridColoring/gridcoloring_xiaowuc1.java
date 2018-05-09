import java.io.*;
import java.util.*;

public class gridcoloring_xiaowuc1 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		char[][] grid = new char[r][];
		for(int i = 0; i < r; i++) {
			grid[i] = br.readLine().toCharArray();
		}
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] != 'R') continue;
				for(int x = i; x < r; x++) {
					for(int y = j; y < c; y++) {
						if(x==i && y==j) continue;
						if(grid[x][y] == 'B') {
							System.out.println(0);
							return;
						}
					}
				}
			}
		}
		int[] lowestForced = new int[c];
		Arrays.fill(lowestForced, -1);
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] == 'B') {
					for(int a = 0; a <= j; a++) {
						lowestForced[a] = Math.max(lowestForced[a], i);
					}
				}
			}
		}
		long[] dp = new long[r+1];
		dp[r] = 1;
		for(int j = 0; j < c; j++) {
			long[] next = new long[r+1];
			for(int i = lowestForced[j]; i < r; i++) {
				if(i >= 0 && grid[i][j] == 'R') break;
				for(int x = i+1; x <= r; x++) {
					next[i+1] += dp[x];
				}
			}
			dp = next;
		}
		long ret = 0;
		for(long out: dp) {
			ret += out;
		}
		System.out.println(ret);
	}
}