import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Solution to Purple Rain
 *  
 * @author vanb
 */
public class purple_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    /**
     * A Region of the string. 
     * It can represent any starting and stopping point.
     * 
     * @author vanb
     */
    private class Region implements Comparable<Region>
    {
        /** Starting character */
        public int start;
        
        /** Stopping point */
        public int stop;
        
        /** Cumulative score over the whole region */
        public int score;
        
        /**
         * Create a Region
         * 
         * @param start Starting point
         * @param stop Stopping point
         * @param score Cumulative score
         */
        public Region( int start, int stop, int score )
        {
            this.start = start;
            this.stop = stop;
            this.score = score;
        }
        
        /**
         * A pretty string for debugging.
         * 
         * @return A pretty string for debugging
         */
        public String toString()
        {
            return "[" + start + " (" + score + ") " + stop + "]";
        }

        @Override
        /**
         * Compare one Region to another.
         * First by score (higher is better)
         * Then by starting point (lower is better)
         * Finally by stopping point (lower is better)
         * 
         * @param other Another region to compare to this one
         * @return >0 if this is better than other, <0 if it's worse, 0 if they're the same
         */
        public int compareTo( Region other )
        {
            int diff = score - other.score;
            if( diff==0 ) diff = other.start - start;
            if( diff==0 ) diff = other.stop - stop;
            return diff;
        }
    }
    
    /**
     * Find the best overall region across a sequence of regions.
     * 
     * @param regions List of regions
     * @return The best overall region
     */
    private Region findBest( List<Region> regions )
    {
        Region best = new Region( 0, 0, Integer.MIN_VALUE );
        Region current = new Region( 0, 0, 0 );
        
        for( Region region : regions )
        {
            // This is what we get if we tack this region on to the end of the current region
            current.stop = region.stop;
            current.score += region.score;
            
            // If this one, standalone, is better, then use it instead.
            if( region.score > current.score )
            {
                current.start = region.start;
                current.score = region.score;
            }
            
            // If the current is better than the best we've seen so far,
            // then remember it.
            if( current.score > best.score )
            {
                best.score = current.score;
                best.start = current.start;
                best.stop = current.stop;
            }
        }
        
        return best;   
    }
    
    /**
     * Do it!
     */
    private void doit()
    {
        // Read in as an array of chars, which will be MUCH more convenient than a String.
        char rbs[] = sc.nextLine().trim().toCharArray();
        
        // We'll reduce it to a sequence of Regions
        List<Region> regions = new ArrayList<Region>( rbs.length );
        
        // We'll (arbitrarily) let B be worth 1, R = -1.
        // We'll group all consecutive Bs together, and all consecutive Rs together.
        // That will leave us with  sequence of regions with scores that alternate sign. 
        // For example, with RRBBBRBBBBRRRRR, the sequence of scores is:
        // -2 3 -1 4 -5 
        char lastrb = '?';
        Region current = null;
        for( int i=0; i<rbs.length; i++ )
        {
            char rb = rbs[i];
            
            // Is this character the same as the immediately previous one?
            if( rb == lastrb )
            {
                // If so, then just extend the current region.
                current.stop = i;
                current.score += (rb=='R' ? -1 : 1);
            }
            else
            {
                // If not, create a new region.
                current = new Region( i, i, rb=='R' ? -1 : 1 );
                regions.add( current );
            }
            lastrb = rb;
        }

        // Find the best where Bs outnumber Rs
        Region best1 = findBest( regions );
        
        // Flip score signs
        for( Region region : regions ) region.score *= -1;
        
        // Find the best where Rs outnumber Bs
        Region best2 = findBest( regions );
        
        // Find the best overall
        Region best = best1.compareTo( best2 )>0 ? best1 : best2;
        
        ps.println( (best.start+1) + " " + (best.stop+1) ); 
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new purple_vanb().doit();
    }

}
