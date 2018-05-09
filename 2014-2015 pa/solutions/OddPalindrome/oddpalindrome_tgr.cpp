#include <iostream>
#include <string>
using namespace std ;
int main() {
   string s ;
   cin >> s ;
   for (int i=0; i+1<s.length(); i++)
      if (s[i] == s[i+1]) {
         cout << "Or not." << endl ;
         return 0 ;
      }
   cout << "Odd." << endl ;
}
