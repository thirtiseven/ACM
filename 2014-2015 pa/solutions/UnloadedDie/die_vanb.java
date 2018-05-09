import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Solution to Unloaded Die
 * 
 * The expected value of a roll of the die is:
 * 
 *     ev = 1*p[1] + 2*p[2] + 3*p[3] + 4*p[4] + 5*p[5] + 6*p[6]
 *     
 *  If we're going to replace some face i with a new value x, the new expected value is
 *  
 *     ev - i*p[i] + x*p[i]
 *     
 *  We want that to be 3.5, so set ev-i*p[i]+x*p[i] = 3.5, and solve for x.
 *  
 *     x = (3.5 - ev + i*p[i])/p[i]
 *     
 *  The difference we're after is |i-x|. Just find that for all 6 faces, and get the minimum.
 * 
 * @author vanb
 */
public class die_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private void doit()
    {
        // Just for convenience, we'll ignore p[0] and only use p[1] through p[6]
        double p[] = new double[7];
        
        // Read probabilities, find Expected Value
        double ev = 0.0;
        for( int i=1; i<=6; i++ ) 
        {
            p[i] = sc.nextDouble();
            ev += i*p[i];
        }
        // Try replacing each of the 6 sides, 
        // find the one with the minimum difference.
        double mindiff = Double.MAX_VALUE;
        for( int i=1; i<=6; i++ ) if( p[i]>0.0000000001 )
        {
            double diff = Math.abs( i - (3.5-ev+i*p[i])/p[i] );  
            if( diff<mindiff ) mindiff = diff;
        }
        
        ps.printf( "%.3f", mindiff );
        ps.println();
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new die_vanb().doit();
    }

}
