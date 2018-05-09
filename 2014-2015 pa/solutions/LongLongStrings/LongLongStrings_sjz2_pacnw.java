import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/**
 * LongLongStrings
 * 
 * @author zeil
 *
 */
public class LongLongStrings_sjz2_pacnw {
	
	private long N;
	private Scanner input;
	
	public class Substring {
		public long start;  // Always expressed in terms of 
		public long stop;   // the original string positions
		boolean insertion;  // only valid of start == stop 
		char c;             // only significant if insertion is true
		
		public Substring (long strt, long stp) {
			start = strt;
			stop = stp;
			insertion = false;
			c = 'x';
		}
		
		public Substring (long strt, long stp, char c) {
			start = strt;
			stop = stp;
			insertion = true;
			this.c = c;
		}
		
		public long length() {
			return stop - start;
		}
		
		public boolean equals(Object obj) {
			if (obj instanceof Substring) {
				Substring s = (Substring)obj;
				if (insertion != s.insertion)
					return false;
				else if (s.insertion)
					return (c == s.c);
				else 
					return start == s.start && stop == s.stop;
			} else {
				return false;
			}
		}
		
		public String toString () {
			String s = "[" + start + ".." + stop + "]";
			if (insertion) {
				return s + ":" + c;
			} else 
				return s;
		}
	}
	
	/**
	 * The LongString class simulates the effects of the string
	 * editor by tracking intervals of character positions affected
	 * by insert and delete operations.
	 * 
	 * @author zeil
	 *
	 */
	public class LongString {
		public LinkedList<Substring> substrings;
		
		public LongString (long N) {
			substrings = new LinkedList<>();
			substrings.add(new Substring(0, N));
		}
		
		public String toString() {
			StringBuffer buf = new StringBuffer();
			buf.append("(");
			boolean first = true;
			for (Substring s: substrings) {
				if (!first) {
					buf.append(", ");
				}
				first = false;
				buf.append(s.toString());
			}
			buf.append(")");
			return buf.toString();
		}
		
		public boolean equals (Object obj) {
			if (obj instanceof LongString) {
				LongString ls = (LongString)obj;
				if (substrings.size() == ls.substrings.size()) {
					return substrings.equals(ls.substrings);
				} else
					return false;
			}
			return false;
		}
		
		
		public void insert(long position, char c) {
			long pos = 0;
			ListIterator<Substring> current = substrings.listIterator();
			while (current.hasNext()) {
				Substring s = current.next();
				if (pos + s.length() > position) {
					if (s.insertion) {
						current.previous();
						current.add(new Substring(pos, pos+1, c));
					} else {
						long beforeIns = position - pos;
						long afterIns = s.length() - beforeIns;
						current.remove();
						if (beforeIns > 0) {
							current.add(new Substring(s.start, s.start+beforeIns));
						}
						current.add(new Substring(s.start+beforeIns, 
								s.start+beforeIns+1, c));
						if (afterIns > 0) {
							current.add(new Substring(s.start+beforeIns, s.stop));
						}
					}
					break;
				}
				pos += s.length();
			}
		}
		
		public void delete(long position) {
			long pos = 0;
			ListIterator<Substring> current = substrings.listIterator();
			while (current.hasNext()) {
				Substring s = current.next();
				if (pos + s.length() > position) {
					if (s.insertion) {
						// This del cancels an earlier insertion
						current.remove();
						if (current.hasPrevious()) {
							Substring leader = current.previous();
							current.next();
							if ((!leader.insertion) && current.hasNext()) {
								Substring follower = current.next();
								if (leader.stop == follower.start && !follower.insertion) {
								// Merge two adjacent substrings
									leader.stop = follower.stop;
									current.remove();
								}
							}
						}
						break;
					} else {
						long beforeDel = position - pos;
						long afterDel = s.length() - beforeDel - 1;
						current.remove();
						if (beforeDel > 0) {
							current.add(new Substring(s.start, s.start+beforeDel));
						}
						if (afterDel > 0) {
							current.add(new Substring(s.start+beforeDel+1, s.stop));
						}
						break;
					}
				}
				pos += s.length();
			}
		}
		
	}

	
	public LongLongStrings_sjz2_pacnw(long n2, Scanner scanIn) {
		this.N = n2;
		input = scanIn;
	}

	public static void solve(BufferedReader input) throws IOException {
		Scanner scanIn = new Scanner(input);
		while (scanIn.hasNext()) {
			long N = 10000000000L ;
			new LongLongStrings_sjz2_pacnw(N, scanIn).solve();
		}
	}
	
	

	private void solve() {
		LongString longString1 = new LongString(N);
		Edit e = Edit.next(input);
		while (e != null) {
			if (e.insert) {
				longString1.insert(e.pos, e.c);
			} else {
				longString1.delete(e.pos);
			}
			e = Edit.next(input);
		}
		LongString longString2 = new LongString(N);
		e = Edit.next(input);
		while (e != null) {
			if (e.insert) {
				longString2.insert(e.pos, e.c);
			} else {
				longString2.delete(e.pos);
			}
			e = Edit.next(input);
		}
		if (longString1.equals(longString2)) {
			System.out.println("0");
		} else {
			System.out.println ("1");
		}
		
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {
		if (args.length > 0) {
			try (BufferedReader input 
					= new BufferedReader(new FileReader(args[0])))
			{
				solve(input);
			}
		} else {
			BufferedReader input 
			    = new BufferedReader (new InputStreamReader(System.in));
			solve(input);
		}
	}
	
	
	public static class Edit {
		boolean insert;
		long pos;
		char c; 
		
		
		public Edit () {
			insert = true;
			pos = 0;
			this.c = ' ';
		}

		public String toString()
		{
			if (insert)
				return "i(" + pos + "," + c + ")";
			else
				return "d(" + pos + ")";
		}
		
		public static Edit next(Scanner in) {
			String op = in.next();
			if (op.equals("E"))
				return null;
			Edit e = new Edit();
			e.insert = op.equals("I");
			e.pos = in.nextLong();
			if (e.insert) {
				e.c = in.next().charAt(0);
			}
			return e;
		}
		
		public boolean equals (Object obj) {
			if (obj instanceof Edit) {
				Edit e = (Edit)obj;
				return insert == e.insert
						&& pos == e.pos
						&& c == e.c;
			} else
				return false;
		}
		
	}
	
}
