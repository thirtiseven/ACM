import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

/**
 * Solution to Rainbow Roads
 * 
 * @author vanb
 */
public class rainbow_bfs_faster_vanb
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private class Road
    {
        public Intersection source, destination;
        public int color;
        
        public Road( Intersection source, Intersection destination, int color )
        {
            this.source = source;
            this.destination = destination;
            this.color = color;
        }
        
        public String toString()
        {
            return "[src:" + source.index + " dst:" + destination.index + "]";
        }
    }
    
    private int count;

    private class Intersection
    {
        public boolean eliminated = false;
        public List<Road> roads = new LinkedList<Road>(); 
        public int index;
        
        public Intersection( int index )
        {
            this.index = index;
        }      
    }
    
    private void doit()
    {
        int n = sc.nextInt();
        
        Intersection intersections[] = new Intersection[n];

        for( int i=0; i<n; i++ ) intersections[i] = new Intersection( i+1 );
        for( int i=0; i<n-1; i++ )
        {
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
            int c = sc.nextInt();
            
            intersections[a].roads.add( new Road( intersections[a], intersections[b], c ) );
            intersections[b].roads.add( new Road( intersections[b], intersections[a], c ) );
        }
        
        count = n;
        int colors[] = new int[n+1];
        Queue<Road> q = new ArrayDeque<Road>(n+n);
        for( Intersection intersection : intersections )
        {
            Arrays.fill( colors, 0 );
            for( Road road : intersection.roads ) ++colors[road.color];
            
            Iterator<Road> it = intersection.roads.iterator();
            while( it.hasNext() ) 
            {
                Road road = it.next();
                if( colors[road.color]>1 )
                {
                    q.add( road );
                    it.remove();
                }
            }
        }
            
        while( !q.isEmpty() )
        {
            Road road = q.poll();
            
            if( !road.destination.eliminated )
            {
                road.destination.eliminated = true;
                --count;
            }
            
            Iterator<Road> it = road.destination.roads.iterator();
            while( it.hasNext() )
            {
                Road nextroad = it.next();
                if( nextroad.destination!=road.source )
                {
                    q.add( nextroad );  
                    it.remove();
                }
            }
            
        }
                
        ps.println( count );
        for( Intersection intersection : intersections ) if( !intersection.eliminated )
        {
            ps.println( intersection.index );
        }
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new rainbow_bfs_faster_vanb().doit();
        //System.exit( 0 );
    }

}
