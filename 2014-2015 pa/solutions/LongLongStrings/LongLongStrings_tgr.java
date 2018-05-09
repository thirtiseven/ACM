import java.util.* ;
public class LongLongStrings_tgr {
   static final long MAXLENGTH = 20000000000L ;
   static Scanner sc ;
   static class Atom {
      Atom(long length_, long loc_, Atom next_) {
         length = length_ ;
         loc = loc_ ;
         newChar = 0 ;
         next = next_ ;
      }
      Atom(char newChar_, Atom next_) {
         length = 1 ;
         loc = -1 ;
         newChar = newChar_ ;
         next = next_ ;
      }
      Atom(Atom a, Atom next_) {
         length = a.length ;
         loc = a.loc ;
         newChar = a.newChar ;
         next = next_ ;
      }
      boolean isOriginal() {
         return newChar == 0 ;
      }
      final long length, loc ;
      final char newChar ;
      final Atom next ;
   }
   static boolean eq(Atom a, Atom b) {
      if (a == null && b == null)
         return true ;
      if (a == null || b == null)
         return false ;
      if (a.newChar != b.newChar)
         return false ;
      if (a.loc != b.loc)
         return false ;
      if (a.length != b.length && a.isOriginal()) {
         if (a.length > b.length)
            return eq(new Atom(a.length-b.length, a.loc+b.length, a.next), b.next) ;
         else
            return eq(a.next, new Atom(b.length-a.length, b.loc+a.length, b.next)) ;
      }
      return eq(a.next, b.next) ;
   }
   static Atom insert(Atom a, long skip, char newC) {
      if (a.length < skip)
         return new Atom(a, insert(a.next, skip-a.length, newC)) ;
      if (a.length == skip)
         return new Atom(a, new Atom(newC, a.next)) ;
      return new Atom(skip, a.loc,
                new Atom(newC, new Atom(a.length-skip, a.loc+skip, a.next))) ;
   }
   static Atom delete(Atom a, long skip) {
      if (a.length <= skip)
         return new Atom(a, delete(a.next, skip-a.length)) ;
      if (skip == 0) {
         if (a.length == 1)
            return a.next ;
         return new Atom(a.length-1, a.loc+1, a.next) ;
      }
      if (a.length == skip + 1)
         return new Atom(a.length-1, a.loc, a.next) ;
      return new Atom(skip, a.loc,
                            new Atom(a.length-skip-1, a.loc+skip+1, a.next)) ;
   }
   static void show(Atom a) {
      if (a == null)
         return ;
      if (a.isOriginal())
         System.out.print("[" + a.length + "@" + a.loc + "]") ;
      else
         System.out.print(a.newChar) ;
      show(a.next) ;
   }
   static Atom SlurpAndExecute() {
      Atom a = new Atom(MAXLENGTH, 0, null) ;
      while (true) {
         String s = sc.next() ;
         if (s.equals("E")) {
//          show(a) ;
//          System.out.println() ;
            return a ;
         }
         Long ind = sc.nextLong() ;
         String newS = null ;
         if (s.equals("I")) {
            newS = sc.next() ;
            a = insert(a, ind, newS.charAt(0)) ;
         } else if (s.equals("D")) {
            a = delete(a, ind) ;
         } else {
            throw new Error("Bad input format; saw command " + s) ;
         }
      }
   }
   public static void main(String[] args) {
      sc = new Scanner(System.in) ;
      Atom a1 = SlurpAndExecute() ;
      Atom a2 = SlurpAndExecute() ;
      if (eq(a1, a2))
         System.out.println("0") ;
      else
         System.out.println("1") ;
   }
}
