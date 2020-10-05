#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   cout << "***MAXIMUM SUB-ARRAY SUM: ALGORITHM 2 O(n^2)***" << endl << endl;
   int n = 10;
   int a[n];
   for(int i = 0; i < n; i++){
      int e = rand() % 20;
      a[i] = e;
   }
   // cout << "Enter " << n << " elements for the array:" << endl;
   // for(int i = 0; i < n; i++) {
   //    cin  >> a[i];
   // }
   cout << "Array: \n";
   for(int i = 0; i < n; i++)
      cout << a[i] << "  ";
   cout << endl;
// maximun sub-array sum starts from here
   int best = 0; // initially the max sum is 0
   for(int i = 0; i < n; i++) { // starting point for the sub-array
      int sum = 0;
      for(int j = i; j < n; j++) { // start adding element into sub-array
        sum += a[j]; // sum of elements 
        best = max(best, sum); //compare the current sum with previous largest sum
      }
   }
   cout << "Maximum sub-array sum: " << best << "\n";
   
   return 0;
}
