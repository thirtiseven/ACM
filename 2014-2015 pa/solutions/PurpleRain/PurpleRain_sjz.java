import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;


public class PurpleRain_sjz {

	private BufferedReader input;

	public PurpleRain_sjz(BufferedReader input) {
		this.input = input;
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {
		if (args.length > 0) {
			try (BufferedReader input
					= new BufferedReader(new FileReader(args[0])))
			{
				new PurpleRain_sjz(input).solve();
			}
		} else {
			BufferedReader input
			    = new BufferedReader (new InputStreamReader(System.in));
			new PurpleRain_sjz(input).solve();
		}
	}

	class Subsequence {
		int start; // inclusive
		int stop; // exclusive
		int sum;

		public Subsequence() {
			start = stop = sum = 0;
		}

		public String toString() {
			return "[" + start + ".." + stop + "]:" + sum;
		}
	}

	private void updateCurrent(Subsequence sub, int pos, int delta) {
		if (sub.sum + delta >= delta) {
			sub.sum += delta;
			sub.stop = pos+1;
		} else {
			sub.sum = delta;
			sub.start = pos;
			sub.stop = pos+1;
		}
	}

	private void solve() throws IOException {
		String line = input.readLine();

		Subsequence currentBlue = new Subsequence();
		Subsequence currentRed = new Subsequence();
		Subsequence overallBlue = new Subsequence();
		Subsequence overallRed = new Subsequence();
		for (int i = 0; i < line.length(); ++i) {
			char c = line.charAt(i);
			int k = (c == 'B') ? 1 : -1;
			updateCurrent(currentBlue, i, k);
			updateCurrent(currentRed, i, -k);
			updateMax(overallBlue, currentBlue);
			updateMax(overallRed, currentRed);
		}
		Subsequence best;
		if (overallBlue.sum > overallRed.sum) {
			best = overallBlue;
		} else if (overallBlue.sum < overallRed.sum) {
			best = overallRed;
		} else {
			// Tied on sum
			if (overallBlue.start < overallRed.start) {
				best = overallBlue;
			} else if (overallBlue.start > overallRed.start) {
				best = overallRed;
			} else {
				// Tied on sum and start
				if (overallBlue.stop < overallRed.stop) {
					best = overallBlue;
				} else {
					best = overallRed;
				}
			}
		}
		System.out.println("" + (best.start+1) + ' ' + best.stop);
	}

	private void updateMax(Subsequence overall, Subsequence current) {
		if (current.sum > overall.sum) {
			overall.sum = current.sum;
			overall.start = current.start;
			overall.stop = current.stop;
		}
	}
}


