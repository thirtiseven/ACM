import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Halfway
 * 
 * Let's look at the case n=10. 
 * Print 1, compare 1 to: 2 3 4 5 6 7 8 9 10 (9 comparisons)
 * Print 2, compare 2 to: 3 4 5 6 7 8 9 10 (8 comparisons)
 * Print 3, compare 3 to: 4 5 6 7 8 9 10 (7 comparisons)
 * Print 4, compare 4 to: 5 6 7 8 9 10 (6 comparisons)
 * Print 5, compare 5 to: 6 7 8 9 10 (5 comparisons)
 * Print 6, compare 6 to: 7 8 9 10 (4 comparisons)
 * Print 7, compare 7 to: 8 9 10 (3 comparisons)
 * Print 8, compare 8 to: 9 10 (2 comparisons)
 * Print 9, compare 9 to: 10 (1 comparison)
 * 
 * That's a total of 45 comparisons ( n*(n-1)/2 ). 
 * The halfway point would be 23, which happens when comparing 3 to 9, so 3 is the correct answer.
 * 
 * Instead of counting down from the top, it's easier to count up from the bottom.
 * We need to find k such that sum(1,k) is half of n*(n-1)/2.
 * So, k*(k+1)/2 = n*(n-1)/4
 * 
 * This solution will use a Binary Search to find k.
 * The answer is then n-k-1.
 * 
 * @author vanb
 */
public class halfway2_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        long n = sc.nextLong();
        
        // Here's our target halfway point
        long target = n*(n-1)/4;
        
        // Use a Binary Search to find k
        long lo = 0;
        long hi = n;       
        long k;
        for(;;)
        {
            k = (lo+hi)/2;
            boolean k1 = (k*(k+1)/2<=target);
            boolean k2 = ((k+1)*(k+2)/2<=target);
            
            if( k1 && !k2 ) break;
            else if( k1 && k2 ) lo=k;
            else hi=k;
        }
        
        ps.println( n-k-1 );
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new halfway2_vanb().doit();
    }

}
