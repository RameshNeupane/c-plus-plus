#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int fix_brackets(string &str)
{
   vector <char> input_vector;
   int count_bracket = 0;
   int i = 0;
   while(true) { // if the close brackets come before the open brackets
      if(str[i] == ')')
         count_bracket++;
      else
         break;
      i++;
   }
   while(str[i] != '\0') {
      if(str[i] == '(')
         input_vector.push_back('(');
      else
         input_vector.pop_back();
      i++;
   }
   int s = input_vector.size(); // size of vector after the operation
   return count_bracket + abs(s);
}

int main()
{
   string input;
   cout << "Enter the input string for fix brackets ('(' and ')' only): ";
   getline(cin, input);
   int num_fix_brackets = fix_brackets(input);
   cout << "Minimum no. of brackets to be fixed: " << num_fix_brackets << endl;
   return 0;
}
