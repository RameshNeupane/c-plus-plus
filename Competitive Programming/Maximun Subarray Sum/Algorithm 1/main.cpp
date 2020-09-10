#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
   cout << "***MAXIMUM SUB-ARRAY SUM: ALGORITHM 1 O(n^3)***" << endl << endl;
   int n = 10;
   int a[n];
   for(int i = 0; i < n; i++){
      int e = rand() % 20;
      a[i] = e;
   }
   cout << "Array: \n";
   for(int i = 0; i < n; i++)
      cout << a[i] << "  ";
   cout << endl;

   int best = 0;
   for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
         int sum = 0;
         for(int k = i; k <= j; k++) {
            sum += a[k];
         }
         best = max(best, sum);
      }
   }
   cout << best << "\n";
   
   return 0;
}
