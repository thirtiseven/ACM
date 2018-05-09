/*  assumes days can be fractional  */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main() {
   double K, P, X ;
   cin >> K >> P >> X ;
   double M = sqrt(P * K / X) ;
   double Mlow = floor(M) ;
   double Mhi = ceil(M) ;
   double CostLow = Mlow * X + P * K / Mlow ;
   double CostHi = Mhi * X + P * K / Mhi ;
   double FinalCost = min(CostHi, CostLow) ;
   cout << fixed << setprecision(3) << FinalCost << endl ;
}
