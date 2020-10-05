#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  cout << "***MAXIMUM SUB-ARRAY SUM: ALGORITHM 3 O(n)***" << endl << endl;
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
  int best = 0, sum = 0; // initially the max sum is 0
  for(int i = 0; i < n; i++) { // starting point for the sub-array
    sum = max(a[i], (sum + a[i]));
    best = max(best, sum);
  }
  cout << "Maximum sub-array sum: " << best << "\n";
  
  return 0;
}
