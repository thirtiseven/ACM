import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;


public class SpinningUp_sjz {
	
	private static final int MaxCost = 999999;
	private BufferedReader input;

	public SpinningUp_sjz(BufferedReader input) {
		this.input = input;
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {
		if (args.length > 0) {
			try (BufferedReader input 
					= new BufferedReader(new FileReader(args[0])))
			{
				new SpinningUp_sjz(input).solve();
			}
		} else {
			BufferedReader input 
			    = new BufferedReader (new InputStreamReader(System.in));
			new SpinningUp_sjz(input).solve();
		}
	}

	private void solve() throws IOException {
		String line = input.readLine();
		int c = makePalindrome (line);
		System.out.println (c);
//System.err.println("memos: size=" + memos.size() 
//	+ "  attempts=" + memoAttempts + "  hits: " + memoHits);
	}

	public int makePalindrome(String wheels) {
		int cost1 = makePalindromeNocarry(wheels);
		int cost2 = makePalindromeWithCarry(wheels);
		return Math.min(cost1, cost2);
	}
	
	
	private HashMap<String, Integer> memos = new HashMap<>();
	private int memoAttempts = 0;
	private int memoHits = 0;
	
	
	
	/**
	 * Compute the smallest number of changes required to make
	 * wheels into a palindrome for the case where a non-zero leading
	 * digit has been located.
	 * 
	 * @param wheels  sequence of digits
	 * @return  minimum number of wheel advances required
	 */
	private int makePalindromeNocarry(String wheels) {
		
		// Base cases: palindromes of length 0 or 1, or larger previously
		// solved problems.
		
		if (wheels.length() == 0) {
			return 0;
		}
		if (wheels.length() == 1) {
				return 0;
		}
		
		boolean leadingDigit = true;
		String journalKey = wheels + ":" + leadingDigit + ":" + false;
		Integer priorAnswer = memos.get(journalKey);
		++memoAttempts;
		if (priorAnswer != null) {
			++memoHits;
			return priorAnswer;
		}
			
		// Given a number of the form LxR where L and R are single
		// digits and x is a string of 1 or more digits. Let x2 be the result of
		// incrementing x. If doing so makes x2 more digits than x, skip
		// following steps involving x2.
		//

		int answer = MaxCost;
		char cL = wheels.charAt(0);
		char cR = wheels.charAt(wheels.length()-1);
		int L = (int)cL - (int)'0';
		int R = (int)cR - (int)'0'; 
		
		String innerWheels = wheels.substring(1, wheels.length()-1);
		
		if (L <= R) {
			// Spin the left wheel up to R (no carry will be generated)
			int spinL = R - L;
			int innerCost = makePalindromeNocarry(innerWheels);
			answer = Math.min(answer, spinL + innerCost);
			
			// Or spin the left wheel up to R -1 and solve the inner system
			// with a carry.
			if (L <= R-1) {
				spinL = R - L - 1;
				innerCost = makePalindromeWithCarry(innerWheels);
				answer = Math.min(answer, spinL + innerCost);					
			}
			

			// Also consider spinning the right wheel up to 0, forcing an
			// increment.  This might or might not cause a carry.
			if (R > 0) {
				int spinR = 10 - R;
				String incr = increment(wheels.substring(0, wheels.length()-1));
				if (incr.length() != wheels.length()) {
					incr = incr + '0';
					innerCost = makePalindromeNocarry(incr);
					answer = Math.min(answer, spinR + innerCost);
				}
			}
			
		}
		
		if (R < L) {
			// Spin the right wheel to L (no carry)
			int spinR = L - R;
			int innerCost = makePalindromeNocarry(innerWheels);
			answer = Math.min(answer, spinR + innerCost);
		}
		if (R <= L) {
			// Or spin it to L+1 and solve the inner problem with a carry
			if (L < 9) {
				int spinR = L+1 - R;
				int innerCost = makePalindromeWithCarry(innerWheels);
				answer = Math.min(answer, spinR + innerCost);					

			}
		}
		
		//System.err.println (wheels + ' ' + withCarry + " => " + answer);
		memos.put(journalKey, answer);
		return answer;
	}

	
	
	/**
	 * Compute the smallest number of changes required to make
	 * wheels into a palindrome for the case where a non-zero leading
	 * digit has been located.
	 * 
	 * @param wheels  sequence of digits
	 * @return  minimum number of wheel advances required
	 */
	private int makePalindromeWithCarry(String wheels) {
		
		// Base cases: palindromes of length 0 or 1, or larger previously
		// solved problems.
		
		if (wheels.length() == 0) {
			return MaxCost;
		}
		if (wheels.length() == 1) {
			// Need to spin the wheel to 0 to force a carry
			return 10 - ((int)wheels.charAt(0) - (int)'0');
		}
		
		boolean leadingDigit = true;
		String journalKey = wheels + ":" + leadingDigit + ":" + true;
		Integer priorAnswer = memos.get(journalKey);
		++memoAttempts;
		if (priorAnswer != null) {
			++memoHits;
			return priorAnswer;
		}
			
		// Given a number of the form LxR where L and R are single
		// digits and x is a string of 1 or more digits. Let x2 be the result of
		// incrementing x. If doing so makes x2 more digits than x, skip
		// following steps involving x2.
		//

		int answer = MaxCost;
		char cL = wheels.charAt(0);
		char cR = wheels.charAt(wheels.length()-1);
		int L = (int)cL - (int)'0';
		int R = (int)cR - (int)'0'; 
		
		String innerWheels = wheels.substring(1, wheels.length()-1);
		

		// Consider spinning the right wheel up to 0, forcing an
		// increment.  This might or might not cause a carry.
		if (R > 0) {
			int spinR = 10 - R;
			String incr = increment(wheels.substring(0, wheels.length()-1));
			if (incr.length() == wheels.length()) {
				incr = incr.substring(1) + '0';
				int innerCost = makePalindromeNocarry(incr);
				answer = Math.min(answer, spinR + innerCost);
			} else {
				incr = incr + '0';
				int innerCost = makePalindromeWithCarry(incr);
				answer = Math.min(answer, spinR + innerCost);					
			}
		}
			
		// If we must have a carry, spin the left wheel to 0 or 9
		// to force one.
		int spinL = 10 - L;
		int innerCost = makePalindromeNocarry("0" + innerWheels + cR);
		answer = Math.min(answer, spinL + innerCost);					

		if (L != 9) {
			spinL = 9 - L;
			innerCost = makePalindromeWithCarry("9" + wheels.substring(1));
			answer = Math.min(answer, spinL + innerCost);					
		} else if (R == 0) {
			innerCost = makePalindromeWithCarry(innerWheels);
			answer = Math.min(answer, innerCost);
		}
		

		
		//System.err.println (wheels + ' ' + withCarry + " => " + answer);
		memos.put(journalKey, answer);
		return answer;
	}
	
	
	
	
	
	// Increment the number in this string
	private String increment(String number) {
		StringBuilder result = new StringBuilder();
		int carry = 1;
		for (int i = number.length()-1; i >= 0; i--) {
			int d = (int)number.charAt(i) - (int)'0';
			d += carry;
			if (d > 9) {
				carry = 1;
				d = d - 10;
			} else {
				carry = 0;
			}
			char dc = (char)(d + '0');
			result.append(dc);
		}
		if (carry > 0) {
			result.append('1');
		}
		return result.reverse().toString();
	}
}

