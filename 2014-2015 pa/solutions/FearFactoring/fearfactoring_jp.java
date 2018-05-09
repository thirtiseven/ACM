import java.util.* ;
/*
 *   Manually translated JP's Python solution from Python to Java.
 *   Any ugliness is my fault.   -tgr
 */
public class fearfactoring_jp {
   static long mypow(long a, long n) {
      long r = 1 ;
      for (long i=0; i<n; i++)
         r *= a ;
      return r ;
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      long a = sc.nextLong() ;
      long b = sc.nextLong() ;
      int m = 1000000 ;
      boolean[] sieve = new boolean[m+1] ;
      int blessa = (int)(b+1-a) ;
      long[] remaining_factor = new long[blessa] ;
      long[] factor_products = new long[blessa] ;
      for (long i=a; i<=b; i++) {
         remaining_factor[(int)(i-a)] = i ;
         factor_products[(int)(i-a)] = 1 ;
      }
      for (int p=2; p<=m; p++) {
         if (sieve[p])
            continue ;
         for (int i=p*2; i<=m; i += p)
            sieve[i] = true ;
         int offset = (int)((((-a) % p) + p) % p) ;
         for (int i=offset; i<blessa; i += p) {
            long cnt = 0 ;
            while (remaining_factor[i] % p == 0) {
               remaining_factor[i] /= p ;
               cnt++ ;
            }
            factor_products[i] *= (mypow(p, (cnt+1))-1) / (p-1) ;
         }
      }
      long ans = 0 ;
      for (long i=a; i<=b; i++)
         if (remaining_factor[(int)(i-a)] > 1)
            ans += factor_products[(int)(i-a)]*(1+remaining_factor[(int)(i-a)]) ;
         else
            ans += factor_products[(int)(i-a)] ;
      System.out.println(ans) ;
   }
}
