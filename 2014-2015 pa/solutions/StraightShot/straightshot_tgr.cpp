#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;
int main() {
   double bot_velocity ;
   int sidewalk_count ;
   double x_distance ;
   cin >> sidewalk_count >> x_distance >> bot_velocity ;
   double avg_y_velocity = 0 ;
   for (int i=0; i<sidewalk_count; i++) {
      double left_edge, right_edge, y_velocity ;
      cin >> left_edge >> right_edge >> y_velocity ;
      avg_y_velocity += (right_edge - left_edge) / x_distance * y_velocity ;
   }
   double x_velocity = -1 ;
// cout << "Average y velocity is " << avg_y_velocity << endl ;
// cout << "Bot velocity is " << bot_velocity << endl ;
   if (abs(avg_y_velocity) < bot_velocity)
      x_velocity = sqrt(bot_velocity * bot_velocity
                                          - avg_y_velocity * avg_y_velocity) ;
   if (x_velocity < 0 || x_velocity * 2 < bot_velocity)
      cout << "Too hard" << endl ;
   else
      cout << fixed << setprecision(3) << x_distance / x_velocity << endl ;
}
