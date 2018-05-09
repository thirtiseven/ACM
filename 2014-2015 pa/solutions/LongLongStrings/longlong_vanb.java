import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Solution to Long Long Strings
 * 
 * @author vanb
 */
public class longlong_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    /**
     * Capture info of a substring.
     * 
     * @author vanb
     */
    private class Substring
    {
        /** Length of the substring */
        public long length;
        
        /** Character. It's one of:
         *     '^' for the beginning of the String
         *     '$' for the end of the String
         *     '?' for a segment of the original String
         *     'A'-'Z' for an inserted character
         */
        public char ch;
        
        /** Start of the substring IN THE ORIGINAL STRING. Only relevant if ch=='?' */
        public long start;
        
        /** End of the substring IN THE ORIGINAL STRING. Only relevant if ch=='?' */
        public long end;
        
        /** Links to previous, next substring */
        public Substring prev, next;
        
        /**
         * Create a Substring.
         * 
         * @param length Length of the substring
         * @param start Start of the substring IN THE ORIGINAL STRING
         * @param end End of the substring IN THE ORIGINAL STRING
         * @param ch 'A'-'Z', or '^', '$' or '?'
         */
        public Substring( long length, long start, long end, char ch )
        {
            this.length = length;
            this.start = start;
            this.end = end;
            this.ch = ch;
            this.prev = this.next = null;
        }
        
        /**
         * Determine if this Substring is the same as another Substring.
         * 
         * @param other The other Substring to compare with this one
         * @return true if they're the same, otherwise false
         */
        public boolean sameAs( Substring other )
        {
            // Have to match in length and character
            boolean ok = length==other.length && ch==other.ch;
            
            // Only have to match in start & end if they're both from the original string
            if( ch=='?' ) ok &= start==other.start && end==other.end;
            
            return ok;
        }
        
        /**
         * Create a pretty String for debugging.
         * 
         * @return A pretty String for debugging
         */
        public String toString()
        {
            String image = "[" + length + "," + ch;
            if( ch=='?' ) image += ",(" + start + "," + end + ")";
            image += "]";
            return image;
        }
    }
    
    /**
     * Print the list of Substrings for debugging.
     * 
     * @param head Head of the list of Substrings
     */
    public void dump( Substring head )
    {
        while( head!=null )
        {
            System.err.println( head );
            head = head.next;
        }
    }
    
    /**
     * Insert a Substring into the list.
     * 
     * @param news New substring to insert
     * @param s Insert news before s
     */
    private void insert( Substring news, Substring s )
    {
        news.prev = s.prev;
        news.next = s;
        s.prev.next = news;
        s.prev = news;        
    }
    
    /**
     * Delete s from the list. 
     * (Really more of an Unlink than a Delete)
     *  
     * @param s Substring to delete from the list
     */
    private void delete( Substring s )
    {  
        s.next.prev = s.prev;
        s.prev.next = s.next;       
    }
    
    /**
     * Split a Substring into 2 Substrings.
     * 
     * @param s Substring to split
     * @param p Point in s to split (0==start of s)
     */
    private void split( Substring s, long p )
    {
        // If p==0, there's no splitting to be done.
        if( p>0 )
        {
            // if p>0, then create a new Substring which is the first p characters of s
            Substring news = new Substring( p, s.start, s.start+p-1, s.ch );
            
            // Insert it before s
            insert( news, s );
        }
        
        // s is now shorter by p
        s.length -= p;
        
        // s's start in the original string is now p further
        s.start += p;
    }
    
    /**
     * Execute one of the programs.
     * 
     * @param program List of commands which form a program
     * @return A list of Substrings which represent the result of executing the program
     */
    private Substring execute( String program[] )
    {
        // Create an initial substring, with a start, contents, and an end.
        Substring head = new Substring( 0L, 0L, 0L, '^' );
        Substring body = new Substring( 10000000000L, 1L, 10000000000L, '?' );
        Substring tail = new Substring( 0, 10000000000L, 10000000000L, '$' );
        
        // Link'em up
        head.next = body;
        body.prev = head;
        body.next = tail;
        tail.prev = body;
        
        // Execute the commands
        for( String command : program )
        {
            // End command - Stop!
            if( command.startsWith( "E" ) ) break;
            
            String tokens[] = command.toUpperCase().trim().split( "\\s+" );
            
            long p = Long.parseLong( tokens[1] );
            
            // Find the chunk that contains p
            Substring chunk = head.next;
            long place = 0;
            while( place+chunk.length<=p )
            {
                place += chunk.length;
                chunk = chunk.next;
            }

            // Whether we insert or delete, we'll need to split the chunk
            split( chunk, p-place );

            if( tokens[0].charAt( 0 )=='I' )
            {
                // Insert is pretty simple - just create a new Substring of length 1 and insert it
                Substring news = new Substring( 1, 0, 0, tokens[2].charAt( 0 ) );
                insert( news, chunk );
            }
            else
            {
                // If the chunk is of length 1, then we've got to get rid of it entirely.
                if( chunk.length==1 )
                {
                    Substring previous = chunk.prev;
                    
                    // Delete the chunk
                    delete( chunk );
                    
                    // If the previous and the next are both from the original string, merge them.
                    if( previous.ch=='?' && previous.next.ch=='?' && previous.end+1==previous.next.start )
                    {
                        previous.next.length += previous.length;
                        previous.next.start = previous.start;
                        delete( previous );
                    }
                }
                else
                {
                    // If the chunk is longer than 1, then just lop off the first character.
                    // This can only happen if the chunk is part of the original string.
                    chunk.length--;
                    chunk.start++;
                }
            }
        }
        
        return head;
    }
    
    /**
     * Do it!
     */
    private void doit()
    {
        // Read in program 1
        String program1[] = new String[2000];
        for( int i=0; ; i++ ) 
        {
            program1[i] = sc.nextLine().trim().toUpperCase();
            if( program1[i].startsWith( "E" ) )break;
        }
        
        // Read in program 2
        String program2[] = new String[2000];
        for( int i=0; ; i++ ) 
        {
            program2[i] = sc.nextLine().trim().toUpperCase();
            if( program2[i].startsWith( "E" ) )break;
        }
        
        // Execute both programs, get the results
        Substring result1 = execute( program1 );
        Substring result2 = execute( program2 );
        
        // Now, compare the results
        boolean same = true;
        for(;;)
        {
            // If we've discovered that they're different, stop.
            // If we've reached the end of both results, stop.
            if( !same || (result1==null && result2==null) ) break;
            
            // If one result ended before the other, then they're not the same.
            if( result1==null && result2!=null ) same = false;
            else if( result1!=null && result2==null ) same = false;
            else
            {
                // If the two results aren't the same, then... well, they're not the same.
                if( !result1.sameAs( result2 ) ) same = false;
                else
                {
                    // If we're good so far, go to the next substring in each result.
                    result1 = result1.next;
                    result2 = result2.next;
                }
            }
        }
        
        ps.println( same ? 0 : 1 );
    }
        
    /**
     * Main!
     * 
     * @param args Command-line args (unused)
     * @throws Exception
     */
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new longlong_vanb().doit();
    }

}
